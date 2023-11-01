#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i, tem = arr[end + 1];
		while (end >= 0)
		{
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end + 1] = tem;
	}
}

int main()
{
	_Bool flag = false;
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int* arr = (int*)malloc(n * m * sizeof(int));
	for (int i = 0; i < m * n; i++)
		scanf("%d", &arr[i]);
	InsertSort(arr, m * n);
	for (int i = 1; i <= n; i++)
	{
		flag = false;
		for (int j = 1; j <= m; j++)
		{
			if (flag)
				printf(" ");
			printf("%d", arr[(i-1) * m + j - 1]);
			flag = true;
		}
		printf("\n");
	}
	return 0;
}
