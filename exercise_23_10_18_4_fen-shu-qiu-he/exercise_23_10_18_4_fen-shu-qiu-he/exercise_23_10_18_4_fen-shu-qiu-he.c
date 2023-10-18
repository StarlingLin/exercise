#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	double sum = 0.0;
	
	for (int i = 1; i <= 100; i++)
		if (1 == i % 2)
			sum += 1 / (double)i;
		else
			sum -= 1 / (double)i;
	
	printf("%lf", sum);
	
	return 0;
}