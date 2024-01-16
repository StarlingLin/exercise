#include <stdio.h>
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
        return (x > y ? x : y); \
}

GENERIC_MAX(int)
GENERIC_MAX(float)

int main()
{
    printf("%d %f", int_max(114514, 1919810), float_max(1.0f, 3.14f));
    return 0;
}