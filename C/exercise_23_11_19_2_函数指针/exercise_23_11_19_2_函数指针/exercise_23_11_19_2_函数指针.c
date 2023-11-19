#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void func()
{
    ;
}

int main()
{
    printf(" func = %p\n", func);
    printf("&func = %p\n", &func);
    return 0;
}