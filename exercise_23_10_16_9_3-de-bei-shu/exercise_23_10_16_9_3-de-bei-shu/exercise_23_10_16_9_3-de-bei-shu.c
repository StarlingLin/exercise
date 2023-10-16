#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i;
	for (i = 0; i <= 100; i++)
		if (i % 3 == 0)
			printf("%d ",i);
	return 0;
}