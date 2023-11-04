#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int fact(int n)
{
	if (n > 1)
		return n * fact(n - 1);
	else
		return 1;
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", fact(n));
	return 0;
}