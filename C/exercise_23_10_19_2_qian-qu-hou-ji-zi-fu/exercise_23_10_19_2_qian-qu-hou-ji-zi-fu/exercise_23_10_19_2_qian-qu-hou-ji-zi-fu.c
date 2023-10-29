#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char ch = 0;

	scanf("%c", &ch);

	printf("%c%c%c\n", ch - 1, ch, ch + 1);

	return 0;
}