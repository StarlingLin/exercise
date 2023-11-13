#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Search(int arr[], int n, int key)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == key)
			return i;
	}
	return -1;
}

int main()
{
	int n = 0, arr[100] = { 0 }, key = 0, ret = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &key);
	ret = Search(arr, n, key);
	if (-1 == ret)
		printf("NULL\n");
	else
		printf("%d\n", ret);
	return 0;
}