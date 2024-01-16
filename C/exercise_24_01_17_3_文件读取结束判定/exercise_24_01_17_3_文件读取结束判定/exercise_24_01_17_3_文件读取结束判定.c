#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fp = fopen("test.txt", "r");
    if (!fp)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c; // ע�⣺int����char��Ҫ����EOF
    while ((c = fgetc(fp)) != EOF)  // ��׼C I/O��ȡ�ļ�ѭ��
        putchar(c);

    if (ferror(fp))
        puts("I/O error when reading.");
    else if (feof(fp))
        puts("End of file reached successfully.");

    fclose(fp);
    fp = NULL;
    return EXIT_SUCCESS;
}