#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int main()
{
	float f = 0.0f;
	
	scanf("%f", &f);

	if (f >= 0)
	{
		if (fabs(f - (int)f) < fabs(f - (int)f - 1))
			printf("%d", (int)f);
		else
			printf("%d", (int)f + 1);
	}
	else
	{
		if (fabs(f - (int)f) < fabs(f - (int)f + 1))
			printf("%d", (int)f);
		else
			printf("%d", (int)f - 1);
	}

	return 0;
}