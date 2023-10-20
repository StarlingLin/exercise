#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	long double x = 0;
	int n = 0;
	long double lp1 = 0;
	long double lp2 = 0;
	long double lpa = 0;
	
	scanf("%Lf%d", &x, &n);

	lp1 = 1;
	lp2 = x;

	if (0 == n)
		printf("1");
	else if (1 == n)
		printf("%.2Lf", x);
	else
	{
		for (int i = 2; i <= n; i++)
		{
			lpa = (2 * (long double)i - 1) / (long double)i * x * lp2 - ((long double)i - 1) / (long double)i * lp1;
			lp1 = lp2;
			lp2 = lpa;
		}
	
		printf("%.2Lf", lpa);
	}


	return 0;
}