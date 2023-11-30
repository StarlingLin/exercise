#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	for (i = 0; i < 44; i++)
		printf("%s\n", strerror(i));
	return 0;
}