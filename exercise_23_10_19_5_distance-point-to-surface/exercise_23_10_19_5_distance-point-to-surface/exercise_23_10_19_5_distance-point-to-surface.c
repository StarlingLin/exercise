#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	float x = 0;
	float y = 0;
	float z = 0;
	float A = 0;
	float B = 0;
	float C = 0;
	float D = 0;
	float d = 0;
	
	scanf("%f%f%f%f%f%f%f", &x, &y, &z, &A, &B, &C, &D);

	d = fabs(A * x + B * y + C * z + D) / sqrt(A * A + B * B + C * C);

	printf("%.3f", d);

	return 0;
}