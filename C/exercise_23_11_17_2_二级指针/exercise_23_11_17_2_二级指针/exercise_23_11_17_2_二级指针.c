#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int n = 0;
    int* pn = &n;
    int** ppn = &pn;
    printf("n   = %d\n", n);
    printf("&n  = %p\n", &n);
    printf("pn  = %p\n", pn);
    printf("&pn = %p\n", &pn);
    printf("ppn = %p\n", ppn);
    return 0;
}