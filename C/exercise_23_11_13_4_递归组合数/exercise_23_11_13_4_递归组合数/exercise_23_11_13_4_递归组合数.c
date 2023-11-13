#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int C(int m, int n)
{
	if (n < 0)
		return 0;
	else if (0 == n)
		return 1;
	else if (1 == n)
		return m;
	else if (m < 2 * n)
		return C(m, m - n);
	else
		return C(m - 1, n - 1) + C(m - 1, n);
}

int main()
{
	int m = 0, n = 0;
	while (scanf("%d%d", &m, &n) != EOF)
		printf("%d\n", C(m, n));
}