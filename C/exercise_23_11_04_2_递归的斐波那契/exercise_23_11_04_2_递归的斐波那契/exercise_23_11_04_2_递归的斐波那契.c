#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Feb(int n)
{
	if (1 == n || 2 == n)
		return 1;
	else
		return Feb(n - 1) + Feb(n - 2);
}

int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
		printf("%d\n", Feb(n));
	return 0;
}