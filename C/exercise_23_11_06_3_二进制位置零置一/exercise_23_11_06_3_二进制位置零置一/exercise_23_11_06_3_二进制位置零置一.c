#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int a = 0, x = 0;
    scanf("%d%d", &a, &x);
    a |= (1 << (x - 1));
    printf("a = %d\n", a);
    a &= ~(1 << (x - 1));
    printf("a = %d\n", a);
    return 0;
}