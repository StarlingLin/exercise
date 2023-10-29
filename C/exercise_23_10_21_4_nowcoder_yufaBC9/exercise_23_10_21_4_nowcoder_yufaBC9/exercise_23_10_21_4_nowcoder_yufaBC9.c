#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char ch = 0;

	scanf("%c", &ch);

	printf("%hd", (short)ch);

	return 0;
}