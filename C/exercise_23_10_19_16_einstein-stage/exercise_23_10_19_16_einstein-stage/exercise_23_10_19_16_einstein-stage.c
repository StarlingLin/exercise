#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	
	while (!(1 == i % 2 && 2 == i % 3 && 4 == i % 5 && 0 == i % 7))
		i++;
	
	printf("%d", i);

	return 0;
}