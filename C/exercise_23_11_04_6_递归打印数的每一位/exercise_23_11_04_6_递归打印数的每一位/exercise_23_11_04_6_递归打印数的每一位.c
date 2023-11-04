#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Print(int n)
{
	if (n > 9)
	{
		Print(n / 10);
	}
	printf("%d\n", n % 10);
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
		Print(n);
	return 0;
}