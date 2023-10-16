#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    int a = 0;
    while (scanf("%d", &a) != EOF)
    {
        if (a >= 140)
            printf("Genius\n");
    }
    return 0;
}