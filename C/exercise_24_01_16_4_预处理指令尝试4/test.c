#include <stdio.h>
#define PRINT(n) printf("The value of "#n" is %d\n", n)

int main()
{
    int a = 10;
    PRINT(a);
    return 0;
}