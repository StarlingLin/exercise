#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0;

	for (int i = 1; i <= 100; i++)
		if (i % 10 == 9 || i / 10 == 9 && i % 10 != i / 10)
			n += 1;
		else if (i % 10 == 9 && i / 10 == 9)
			n += 2;

	printf("%d", n);

	return 0;
}