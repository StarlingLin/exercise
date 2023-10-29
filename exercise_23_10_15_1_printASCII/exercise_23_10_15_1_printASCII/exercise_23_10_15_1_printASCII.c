#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	for (i = 32; i <= 127; i++)
	{
		printf(" % c ", i);
		if (i % 16 == 15)
			printf("\n");
	}
	return 0;
}