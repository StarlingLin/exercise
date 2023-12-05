#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n = 0;

void print(int* a, int num)
{
	printf("%d=%d", n, a[0]);
	for (int i = 1; i < num + 1; i++)
		printf("+%d", a[i]);
	printf("\n");
}

_Bool isdown(int* a, int num)
{
	for (int i = 0; i < num; i++)
		if (a[i] < a[i + 1])
			return false;
	return true;
}

void dec(const int n, int* a, int k)
{
	for (int i = n - 1; i > 0; i--)
	{
		a[k] = i, a[k + 1] = n - i;
		if (isdown(a, k + 1))
			print(a, k + 1);
		if (n - i > 1)
			dec(n - i, a, k + 1);
	}
}

int main()
{
	scanf("%d", &n);
	int* a = (int*)malloc(n * sizeof(int));
	dec(n, a, 0);
	return 0;
}

