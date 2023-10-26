#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;

	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (i == 1 || i == n || j == 1 || j == n)
					printf("* ");
				else
					printf("  ");
			printf("\n");
		}
	}

	return 0;
}