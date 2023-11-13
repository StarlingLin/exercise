#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

float Hermite(int n, float x)
{
	if (0 == n)
		return 1;
	else if (1 == n)
		return 2 * x;
	else
		return 2 * x * Hermite(n - 1, x) - 2 * (n - 1) * Hermite(n - 2, x);
}

int main()
{
	int n = 0;
	float x = 0.0f;
	while (scanf("%d%f", &n, &x) != EOF)
		printf("%.2f\n", Hermite(n, x));
}

