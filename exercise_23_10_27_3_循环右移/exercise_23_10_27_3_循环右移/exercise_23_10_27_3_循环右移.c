#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void push(int arr[], int n)
{
	int swi = 0;
	swi = arr[n - 1];
	for (int i = n - 1; i >= 1; i--)
		arr[i] = arr[i - 1];
	arr[0] = swi;
}

int main()
{
	_Bool flag = false;
	int n = 0;
	int j = 0;
	scanf("%d%d", &n, &j);
	int* arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < j; i++)
	{
		push(arr, n);
	}

	for (int i = 0; i < n; i++)
	{
		if (flag)
			printf(" ");
		printf("%d", arr[i]);
		flag = true;
	}

	return 0;
}