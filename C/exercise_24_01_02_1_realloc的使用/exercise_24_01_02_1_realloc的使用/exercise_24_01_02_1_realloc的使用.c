#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = (int*)calloc(10, sizeof(int));
	if (p == NULL)
	{
		perror("calloc");
		return 1;
	}
	int* q = (int*)realloc(p, 20 * sizeof(int));
	if (q == NULL)
	{
		perror("realloc");
		return 1;
	}
	p = q;
	free(p);
	p = q = NULL;
	return 0;
}