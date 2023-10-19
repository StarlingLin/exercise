#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;

	scanf("%f%f%f", &a, &b, &c);

	a > b ? d = a, a = b, b = d : 0;
	a > c ? d = a, a = c, c = d : 0;
	b > c ? d = b, b = c, c = d : 0;

	printf("%.1f %.1f %.1f", a, b, c);

	return 0;
}