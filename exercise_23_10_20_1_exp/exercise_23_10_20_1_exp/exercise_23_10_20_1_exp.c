#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

float fc(float x, int n)
{
	float fca = 1;
	
	for (int k = 1; k <= n; k++)
		fca = fca * x / k;
	
	return fca;
}

int main()
{
	float x = 0;
	float e = 0;

	scanf("%f", &x);

	for (int i = 0; i < 101; i++)
	{
		e += fc(x, i);
	}

	printf("%.2f", e);

	return 0;
}