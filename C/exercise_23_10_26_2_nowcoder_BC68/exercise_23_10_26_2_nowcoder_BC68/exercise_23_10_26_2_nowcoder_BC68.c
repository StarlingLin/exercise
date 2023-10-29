#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	int n = 0;

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				if (i == j || (n - 1 == i + j))
					printf("*");
				else
					printf(" ");
			printf("\n");
		}
	}
	return 0;
}