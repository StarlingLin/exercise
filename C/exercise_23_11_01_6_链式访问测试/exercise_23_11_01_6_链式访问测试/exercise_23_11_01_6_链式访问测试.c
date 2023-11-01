#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	printf("%d\n", printf("%d", printf("%d", 123)));
	printf("%d \n", printf("%d ", printf("%d ", 123)));
	return 0;
}