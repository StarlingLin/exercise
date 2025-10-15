#include <stdio.h>
#include <stdlib.h>

#define MAPSIZE 100

struct map
{
    int m_addr; 
    int m_size; 
};

static struct map mem[MAPSIZE] = { {0, 0} }; 

static void erase_entry(struct map *p)   
{
    while (p->m_size || (p + 1)->m_size)
    {
        p->m_addr = (p + 1)->m_addr;
        p->m_size = (p + 1)->m_size;
        ++p;
    }
}

static void show_map(void)   
{
    puts("\nAddress\tSize");
    for (struct map *p = mem; p->m_size; ++p)
        printf("%d\t%d\n", p->m_addr, p->m_size);
}

int BF_malloc(struct map *mp, int size) 
{
    struct map *best = NULL;
    for (struct map *p = mp; p->m_size; ++p)
        if (p->m_size >= size && (!best || p->m_size < best->m_size))
            best = p;

    if (!best)
        return -1;

    int addr = best->m_addr;
    best->m_addr += size;
    best->m_size -= size;
    if (best->m_size == 0)
        erase_entry(best);

    return addr;
}

int WF_malloc(struct map *mp, int size)  
{
    struct map *worst = NULL;
    for (struct map *p = mp; p->m_size; ++p)
        if (p->m_size >= size && (!worst || p->m_size > worst->m_size))
            worst = p;

    if (!worst)
        return -1;

    int addr = worst->m_addr;
    worst->m_addr += size;
    worst->m_size -= size;
    if (worst->m_size == 0)
        erase_entry(worst);

    return addr;
}

void mfree(struct map *mp, int addr, int size)
{
    struct map *p = mp;

    while (p->m_size && p->m_addr < addr)
        ++p;  
    if (p > mp && (p - 1)->m_addr + (p - 1)->m_size == addr)
    {
        (p - 1)->m_size += size;
        if (addr + size == p->m_addr)
        {
            (p - 1)->m_size += p->m_size;
            erase_entry(p);
        }
        return;
    }

    if (addr + size == p->m_addr)
    {
        p->m_addr = addr;
        p->m_size += size;
        return;
    }

    struct map *tail = mp;
    while (tail->m_size)
        ++tail;

    if (tail + 1 - mp >= MAPSIZE)
    {
        fputs("map overflow\n", stderr);
        exit(EXIT_FAILURE);
    }

    while (tail >= p)  
    {
        *(tail + 1) = *tail;
        --tail;
    }
    p->m_addr = addr;
    p->m_size = size;
}

static void init_map(void)
{
    int addr, size;
    puts("输入起始地址和总大小（例如：0 100）：");
    if (scanf("%d %d", &addr, &size) != 2 || size <= 0)
        exit(EXIT_FAILURE);

    mem[0].m_addr = addr;
    mem[0].m_size = size;
}

int main(void)
{
    init_map();

    char algo;
    puts("选择算法 (b=BF, w=WF)：");
    if (scanf(" %c", &algo) != 1 || (algo != 'b' && algo != 'w'))
        return 0;

    while (1)
    {
        show_map();
        puts("\n1-申请  2-释放  0-退出：");

        int op;
        if (scanf("%d", &op) != 1)
            break;

        if (op == 1)   
        {
            int sz;
            puts("输入申请大小：");
            scanf("%d", &sz);
            int addr = (algo == 'b') ? BF_malloc(mem, sz)
                                      : WF_malloc(mem, sz);
            if (addr == -1)
                puts("申请失败：可用空间不足");
            else
                printf("已分配：地址=%d 大小=%d\n", addr, sz);
        }
        else if (op == 2)     
        {
            int addr, sz;
            puts("输入释放的起始地址和大小：");
            scanf("%d %d", &addr, &sz);
            mfree(mem, addr, sz);
        }
        else
            break;
    }
    return 0;
}
