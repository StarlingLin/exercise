#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m = 3, n = 5;
	int** arr = (int**)malloc(n * sizeof (int*));
	for (int i = 0; i < n; i++)
		arr[i] = (int*)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = i + j;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%5d",arr[i][j]);
		printf("\n");
	}
	return 0;
}