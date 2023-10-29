#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
    int i, j;
    int col[6] = { 0x060,0x060,0xfff,0xfff,0x090,0x090 };
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if ((col[i] >> j) & 0x001)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
