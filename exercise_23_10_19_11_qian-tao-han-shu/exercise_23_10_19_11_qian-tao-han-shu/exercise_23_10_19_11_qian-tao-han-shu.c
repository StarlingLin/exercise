#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	float x = 0;

	scanf("%f", &x);

	for (int i = 1; i <= 5; i++)
		x = 1 + 1 / x;

	printf("%.3f", x);

	return 0;
}