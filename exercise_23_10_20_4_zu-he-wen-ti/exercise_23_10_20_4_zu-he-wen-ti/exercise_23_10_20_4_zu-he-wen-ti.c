#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

long long jc(short k)
{
	long long jca = 1;

	for (short j = 1; j <= k; j++)
		jca *= j;

	return jca;
}

int main()
{
	int m = 0;
	int n = 0;
	int f = 0;

	scanf("%d%d", &m, &n);

	if (m < n && m > 0 && n > 0)
		printf("0");
	else if (m == n && m > 0 && n > 0)
		printf("1");
	else if (m > n && m > 0 && n > 0)
	{
		f = jc(m) / jc(m - n) / jc(n);
		printf("%ld", f);
	}
	else
		printf("-1");

	return 0;
}