#include <stdio.h>
#include <stdlib.h>

#define MALLOC(size, TYPE) ((TYPE*)malloc(size*sizeof(TYPE)))

int main()
{
    int *p = MALLOC(114514, int);
    printf("%d", malloc_usable_size(p));
    free(p);
    p = NULL;
    return 0;
}