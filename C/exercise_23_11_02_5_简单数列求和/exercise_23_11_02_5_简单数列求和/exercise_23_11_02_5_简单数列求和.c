#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	scanf("%d", &a);
	if (a >= 0 && a <= 9)
		printf("%d", (1 + 11 + 111 + 1111 + 11111) * a);
	return 0;
}