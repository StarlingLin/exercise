#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Ack(int m, int n)
{
	if (0 == m)
		return n + 1;
	else if (0 == n)
		return Ack(m - 1, 1);
	else if (m > 0 && n > 0)
		return Ack(m - 1, Ack(m, n - 1));
	else
		return 0;
}

int main()
{
	int m = 0, n = 0;
	scanf("%d%d", &m, &n);
	printf("%d", Ack(m, n));
	return 0;
}