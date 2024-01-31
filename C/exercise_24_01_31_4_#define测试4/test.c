#include <stdio.h>
#define GENERIC_MAX(type)           \
    type type##_max(type x, type y) \
    {                               \
        return x > y ? x : y;       \
    }

GENERIC_MAX(int)
GENERIC_MAX(float)

int main()
{
    printf("%d\n", int_max(3, 4));
    printf("%f\n", float_max(3.0f, 4.0f));
}