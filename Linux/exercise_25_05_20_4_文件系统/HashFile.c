#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HashFile.h"

int hashfile_creat(const char *filename, mode_t mode, int reclen, int total_rec_num)
{
    struct HashFileHeader hfh;
    int fd;
    int rtn;
    char *buf;
    hfh.sig = 31415926;
    hfh.reclen = reclen;
    hfh.total_rec_num = total_rec_num;
    hfh.current_rec_num = 0;
    fd = creat(filename, mode);
    if (fd != -1)
    {
        rtn = write(fd, &hfh, sizeof(struct HashFileHeader));
        if (rtn != -1)
        {
            buf = (char *)malloc((reclen + sizeof(struct CFTag)) * total_rec_num);
            memset(buf, 0, (reclen + sizeof(struct CFTag)) * total_rec_num);
            rtn = write(fd, buf, (reclen + sizeof(struct CFTag)) * total_rec_num);
            free(buf);
        }
        close(fd);
        return rtn;
    }
    close(fd);
    return -1;
}

int hashfile_open(const char *filename, int flags, mode_t mode)
{
    int fd = open(filename, flags, mode);
    struct HashFileHeader hfh;
    if (read(fd, &hfh, sizeof(struct HashFileHeader)) != -1)
    {
        lseek(fd, 0, SEEK_SET);
        if (hfh.sig == 31415926)
            return fd;
    }
    return -1;
}

int hashfile_close(int fd)
{
    return close(fd);
}

int hashfile_read(int fd, int keyoffset, int keylen, void *buf)
{
    struct HashFileHeader hfh;
    readHashFileHeader(fd, &hfh);
    int offset = hashfile_findrec(fd, keyoffset, keylen, buf);
    if (offset != -1)
    {
        lseek(fd, offset + sizeof(struct CFTag), SEEK_SET);
        return read(fd, buf, hfh.reclen);
    }
    return -1;
}

int hashfile_write(int fd, int keyoffset, int keylen, void *buf)
{
    return hashfile_saverec(fd, keyoffset, keylen, buf);
}

int hashfile_delrec(int fd, int keyoffset, int keylen, void *buf)
{
    int offset = hashfile_findrec(fd, keyoffset, keylen, buf);
    if (offset == -1)
        return -1;

    struct CFTag tag;
    read(fd, &tag, sizeof(struct CFTag));
    tag.free = 0;
    lseek(fd, offset, SEEK_SET);
    write(fd, &tag, sizeof(struct CFTag));

    struct HashFileHeader hfh;
    readHashFileHeader(fd, &hfh);
    int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);
    offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
    lseek(fd, offset, SEEK_SET);
    read(fd, &tag, sizeof(struct CFTag));
    tag.collision--;
    lseek(fd, offset, SEEK_SET);
    write(fd, &tag, sizeof(struct CFTag));

    hfh.current_rec_num--;
    lseek(fd, 0, SEEK_SET);
    write(fd, &hfh, sizeof(struct HashFileHeader));
    return 0;
}

int hashfile_findrec(int fd, int keyoffset, int keylen, void *buf)
{
    struct HashFileHeader hfh;
    readHashFileHeader(fd, &hfh);
    int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);
    int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
    lseek(fd, offset, SEEK_SET);

    struct CFTag tag;
    read(fd, &tag, sizeof(struct CFTag));
    char count = tag.collision;
    if (count == 0)
        return -1;

recfree:
    if (tag.free == 0)
    {
        offset += hfh.reclen + sizeof(struct CFTag);
        lseek(fd, offset, SEEK_SET);
        read(fd, &tag, sizeof(struct CFTag));
        goto recfree;
    }

    char *p = (char *)malloc(hfh.reclen);
    read(fd, p, hfh.reclen);
    char *p1 = (char *)buf + keyoffset;
    char *p2 = p + keyoffset;
    int j = 0;
    while ((*p1 == *p2) && (j < keylen))
    {
        p1++;
        p2++;
        j++;
    }
    if (j == keylen)
    {
        free(p);
        return offset;
    }
    if (addr == hash(keyoffset, keylen, p, hfh.total_rec_num))
    {
        count--;
        if (count == 0)
        {
            free(p);
            return -1;
        }
    }
    free(p);
    offset += hfh.reclen + sizeof(struct CFTag);
    lseek(fd, offset, SEEK_SET);
    read(fd, &tag, sizeof(struct CFTag));
    goto recfree;
}

int hashfile_saverec(int fd, int keyoffset, int keylen, void *buf)
{
    if (checkHashFileFull(fd))
        return -1;

    struct HashFileHeader hfh;
    readHashFileHeader(fd, &hfh);
    int addr = hash(keyoffset, keylen, buf, hfh.total_rec_num);
    int offset = sizeof(struct HashFileHeader) + addr * (hfh.reclen + sizeof(struct CFTag));
    lseek(fd, offset, SEEK_SET);

    struct CFTag tag;
    read(fd, &tag, sizeof(struct CFTag));
    tag.collision++;
    lseek(fd, -sizeof(struct CFTag), SEEK_CUR);
    write(fd, &tag, sizeof(struct CFTag));

    while (tag.free != 0)
    {
        offset += hfh.reclen + sizeof(struct CFTag);
        if (offset >= lseek(fd, 0, SEEK_END))
            offset = sizeof(struct HashFileHeader);
        lseek(fd, offset, SEEK_SET);
        read(fd, &tag, sizeof(struct CFTag));
    }

    tag.free = 1;
    lseek(fd, -sizeof(struct CFTag), SEEK_CUR);
    write(fd, &tag, sizeof(struct CFTag));
    write(fd, buf, hfh.reclen);

    hfh.current_rec_num++;
    lseek(fd, 0, SEEK_SET);
    return write(fd, &hfh, sizeof(struct HashFileHeader));
}

int hash(int keyoffset, int keylen, void *buf, int total_rec_num)
{
    int i, addr = 0;
    char *p = (char *)buf + keyoffset;
    for (i = 0; i < keylen; i++)
        addr += (int)(*p++);
    return addr % (int)(total_rec_num * COLLISIONFACTOR);
}

int readHashFileHeader(int fd, struct HashFileHeader *hfh)
{
    lseek(fd, 0, SEEK_SET);
    return read(fd, hfh, sizeof(struct HashFileHeader));
}

int checkHashFileFull(int fd)
{
    struct HashFileHeader hfh;
    readHashFileHeader(fd, &hfh);
    return hfh.current_rec_num >= hfh.total_rec_num;
}
