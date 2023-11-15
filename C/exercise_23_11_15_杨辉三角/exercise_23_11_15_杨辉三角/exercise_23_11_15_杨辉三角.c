#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int fact(int n)
{
	if (n > 0)
		return n * fact(n - 1);
	else
		return 1;
}

int C(int m, int n)
{
	return fact(m) / fact(n) / fact(m - n);
}

int main()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < i + 1; j++)
			printf("%4d", C(i, j));
		printf("\n");
	}
	return 0;
}