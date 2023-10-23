#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int CommonDivisor(int a, int b)
{
	int c = 0;

	do
	{
		c = a % b;
		a = b;
		b = c;
	} while (c != 0);

	return a;
}

int main()
{
	int m = 0;
	int n = 0;

	scanf("%d%d", &m, &n);

	printf("%d", CommonDivisor(m, n));

	return 0;
}