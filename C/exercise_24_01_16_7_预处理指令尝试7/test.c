#include <stdio.h>

int main()
{
    printf("%d", X);
    //编译时使用-D添加定义
    //gcc -D X=114514 test.c -E -o test.i
    return 0;
}