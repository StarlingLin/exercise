#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;
	int m = 0;
	scanf("%d%d", &n, &m);
	int matrix[10][10] = { 0 };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &matrix[j][i]);//×ªÖÃÂ¼Èë

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}