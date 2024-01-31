#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p, size, TYPE) TYPE *p = ((TYPE*)malloc(size*sizeof(TYPE)))

int main()
{
    MALLOC(p, 114514, int);
    printf("%d\n", malloc_usable_size(p));
    free(p);
    p = NULL;
    return 0;
}