#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n = 0, m = 0;
	char arr[10] = { 0 };
	scanf_s("%d%x%s", &n, &m, arr, 10);
	printf("n=%d m=%d arr=%s\n", n, m, arr);
	return 0;
}