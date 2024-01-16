#include <stdio.h>

int main()
{
#define X 114514
    printf("%d\n", X);
#undef X
    printf("X\n");
    return 0;
}