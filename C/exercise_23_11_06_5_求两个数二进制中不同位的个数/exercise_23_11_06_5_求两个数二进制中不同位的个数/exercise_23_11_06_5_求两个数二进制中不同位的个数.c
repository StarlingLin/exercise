#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int m = 0, n = 0, cnt = 0, inttotal = 32;
	scanf("%d%d", &m, &n);
	do
	{
		if (m % 2 != n % 2)
			cnt++;
	} while (m >>= 1, n >>= 1, inttotal--, inttotal > 0);
	printf("%d\n", cnt);
}