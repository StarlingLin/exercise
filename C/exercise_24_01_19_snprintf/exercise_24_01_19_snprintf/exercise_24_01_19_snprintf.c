#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	char str[100];
	snprintf(str, 100, "Hello %s", "World!");
	printf("%s\n", str);
	return 0;
}