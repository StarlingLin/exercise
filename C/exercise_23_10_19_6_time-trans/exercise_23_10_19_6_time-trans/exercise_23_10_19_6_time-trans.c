#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int sec = 0;

	scanf("%d", &sec);

	printf("%02d:%02d:%02d", sec / 3600 % 24, sec % 3600 / 60, sec % 60);

	return 0;
}