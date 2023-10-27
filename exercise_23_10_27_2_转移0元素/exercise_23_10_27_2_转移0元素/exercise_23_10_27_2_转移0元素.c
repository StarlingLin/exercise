#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void forward(int arr[], int j, int m)
{
	for (int i = j; i < m - 1; i++)
		arr[i] = arr[i + 1];
}

int main()
{
	_Bool flag = false;
	int n = 0;
	scanf("%d", &n);
	int m = n;
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++)
		if (0 == arr[i])
		{
			forward(arr, i, m);
			n--, i--;
		}
	for (int i = n; i < m; i++)
		arr[i] = 0;

	for (int i = 0; i < m; i++)
	{
		if (flag)
			printf(" ");
		printf("%d", arr[i]);
		flag = true;
	}
	return 0;
}