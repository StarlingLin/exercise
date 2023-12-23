#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    long num = 0;
    FILE* fp = NULL;
    if ((fp = fopen("114514.dat", "r")) == NULL)
    {
        printf("Can¡¯t open the file!");
        exit(0);
    }
    while (fgetc(fp) != EOF)
    {
        num++;
    }
    printf("num=%d\n", num);
    fclose(fp);
    return 0;
}