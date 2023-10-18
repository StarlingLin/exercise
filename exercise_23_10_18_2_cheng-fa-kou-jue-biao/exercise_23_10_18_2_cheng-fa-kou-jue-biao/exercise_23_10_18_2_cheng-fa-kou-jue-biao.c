#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i, j, k;

	for (i = 0; i < 9; i++)
	{
		printf("%d|", i + 1);

		for (j = 0; j <= i; j++)
			printf("%d¡Á%d=%d\t", j + 1, i + 1, (i + 1) * (j + 1));
		
		printf("\n");
	}

	printf("*|");

	for (k = 1; k <= 9; k++)
		printf("%d\t", k);

	return 0;
}