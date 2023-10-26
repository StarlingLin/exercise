#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;
	int ans = 0;
	int cnt = 0;

	do
	{
		scanf("%d", &n);
		ans += n;
		cnt++;
	} while (cnt < 10);

	printf("%d", ans / 10);

	return 0;
}