#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int cnt = 1;

void Cnt(int n, int k)
{
	cnt++;
	if ((n * 2 / 5) > k)
		Cnt(n * 2 / 5, k);
	if ((n - n * 2 / 5) > k)
		Cnt(n - n * 2 / 5, k);
}

int main()
{
	int n = 0, k = 0;
	scanf("%d%d", &n, &k);
	if (n > k)
		Cnt(n, k);
	printf("%d", cnt);
	return 0;
}