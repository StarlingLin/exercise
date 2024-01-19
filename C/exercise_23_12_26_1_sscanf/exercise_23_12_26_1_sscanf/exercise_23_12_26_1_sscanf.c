#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a = 0;
	char* arr = (int*)malloc(100 * sizeof(int));
	char str[100] = { 0 };
	sscanf(" 114514 afjoiweaj jiojl", "%d%s%s", &a, arr, str);
	printf("%d - %s - %s", a, arr, str);
	return 0;
}