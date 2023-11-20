#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

_Bool IsLeapYear(int y)
{
    if (0 == y % 400 || 0 != y % 100 && 0 == y % 4)
        return true;
    return false;
}

int main()
{
    int m = 0, y = 0;
    while (scanf("%d%d", &y, &m) != EOF)
    {
        if (IsLeapYear(y) && (2 == m))
            printf("29\n");
        else if (2 == m)
            printf("28\n");
        else if (4 == m || 6 == m || 9 == m || 11 == m)
            printf("30\n");
        else
            printf("31\n");
    }
    return 0;
}