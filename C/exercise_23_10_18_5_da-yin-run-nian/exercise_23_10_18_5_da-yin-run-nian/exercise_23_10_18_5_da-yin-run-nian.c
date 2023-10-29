#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	for (int i = 1000; i <= 2000; i++)
		if (i % 100 != 0 && i % 4 == 0 || i % 400 == 0)
			printf("%d\t", i);
	return 0;
}