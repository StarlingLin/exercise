#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int SearchM(int arr[], int n)
{
	if (n >= 0)
	{
		if (arr[n] > SearchM(arr, n - 1))
			return arr[n];
		else
			return SearchM(arr, n - 1);
	}
	else
		return;
}

int main()
{
	int n = 0, arr[100] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	printf("%d", SearchM(arr, n));
	return 0;
}