#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)malloc(114514);
	printf("%d\n", malloc_usable_size(p));
	free(p);
	p = NULL;
	return 0;
}