#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int bottle = 20;
	int drink = 20;
	do
	{
		drink += bottle / 2;
		bottle = bottle % 2 + bottle / 2;
	} while (bottle > 1);
	printf("%d\n", drink);
	return 0;
}