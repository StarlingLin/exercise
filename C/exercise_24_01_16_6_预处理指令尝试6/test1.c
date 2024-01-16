#include <stdio.h>

int main()
{
    #define X 114514
    printf("%d\n", X);
    #define X 1919810   //重定义警告
    printf("%d\n", X);
    return 0;
}