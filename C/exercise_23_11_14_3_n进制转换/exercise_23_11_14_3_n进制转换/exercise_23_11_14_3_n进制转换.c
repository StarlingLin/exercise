#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void trans(long long x, int y)
{
    if (x == 0)
        return;
    trans(x / y, y);
    if (x % y <= 9)
        printf("%d", x % y);
    else
        printf("%c", x % y + 55);
}

int main(void)
{
    long long n;
    int b;
    scanf("%lld%d", &n, &b);
    if (n == 0)
        printf("0");
    else
        trans(n, b);
    return 0;
}