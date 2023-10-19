#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	float c = 0;
	float f = 0;

	scanf("%f", &c);

	f = c * 9 / 5 + 32;

	printf("%.3f", f);

	return 0;
}