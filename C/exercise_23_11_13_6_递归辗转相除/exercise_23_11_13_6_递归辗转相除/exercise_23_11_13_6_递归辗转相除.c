#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int CommonDivisor(int a, int b)
{
	if (a % b != 0)
		return CommonDivisor(b, a % b);
	else
		return b;
}

int main()
{
	int m = 0;
	int n = 0;
	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", CommonDivisor(m, n));
	return 0;
}