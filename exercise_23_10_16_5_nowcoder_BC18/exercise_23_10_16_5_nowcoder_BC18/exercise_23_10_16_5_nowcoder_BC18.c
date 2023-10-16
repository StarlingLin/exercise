#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d\n", a / b, a % b);
    return 0;
}