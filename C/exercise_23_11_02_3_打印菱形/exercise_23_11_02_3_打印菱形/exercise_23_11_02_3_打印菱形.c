#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int w = 13;
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= w; j++)
			if (i + j > (w + 1) / 2 && i + j <= (3 * w + 1) / 2 && i <= j + w / 2 && i >= j - w / 2)
				printf("*");
			else
				printf(" ");
		printf("\n");
	}
	return 0;
}