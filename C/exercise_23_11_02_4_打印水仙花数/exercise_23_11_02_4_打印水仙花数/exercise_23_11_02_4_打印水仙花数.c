#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#define LIM 100000

int main()
{
	for (int i = 1; i <= LIM; i++)
	{
		int j = i, k = i;
		while (k != 0)
		{
			j -= (k % 10) * (k % 10) * (k % 10);
			k /= 10;
		}
		if (0 == j)
			printf("%d\n", i);
	}
	return 0;
}