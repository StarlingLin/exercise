#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void PrintOdd(int n)
{
	if (n > 0)
	{
		PrintOdd(n >> 2);
		printf("%d", n % 2);
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	PrintOdd(n);
	printf("\n");
	PrintOdd(n >> 1);
	return 0;
}