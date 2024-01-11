#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int i;
	long arr[];
} stt;

int main()
{
	stt* p = (stt*)malloc(sizeof(stt) + 40 * sizeof(long));
	if (p == NULL)
	{
		perror("malloc-p");
		exit(EXIT_FAILURE);
	}

	p->i = 40;
	for (int i = 0; i < 40; i++)
		p->arr[i] = i + 1;
	for (int i = 0; i < 40; i++)
		printf("%2ld\t", (*p).arr[i]);

	free(p);
	p = NULL;
	return 0;
}