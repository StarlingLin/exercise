#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	unsigned n = 0;
	long double pi = 1;
	long double fi = 1;

	scanf("%u", &n);

	for (unsigned i = 1; i <= n; i++)
	{
		fi = i;
		pi *= (2 * fi / (2 * fi - 1)) * (2 * fi / (2 * fi + 1));
	}

	pi *= 2;

	printf("%.10Lf", pi);

	return 0;
}