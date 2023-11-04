#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int DigitSum(int n)
{
	if (n > 0)
		return n % 10 + DigitSum(n / 10);
	else
		return 0;
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", DigitSum(n));
	return 0;
}