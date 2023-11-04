#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int pow(int n, int k)
{
	if (1 == k)
		return n;
	else
		return (n * pow(n, k - 1));
}

int main()
{
	int n = 0, k = 0;
	while (scanf("%d%d", &n, &k) != EOF)
		printf("%d\n", pow(n, k));
	return 0;
}