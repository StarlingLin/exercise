#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	float a = 0;
	float x = 0;
	float y = 0;
	float pi = 3.1415926f;

	scanf("%f%f", &a, &x);

	y = sin(x) / (a * x) + fabs(cos(pi * 0.5 * x));

	printf("%.3f",y);

	return 0;
}