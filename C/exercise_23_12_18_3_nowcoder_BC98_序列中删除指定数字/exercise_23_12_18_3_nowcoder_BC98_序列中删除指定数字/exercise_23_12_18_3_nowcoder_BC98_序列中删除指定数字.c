#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int n = 0, key = 0, arr[51] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &key);
	for (int i = 0; i < n; i++)
		if (arr[i] == key)
		{
			for (int j = i; j < n - 1; j++)
				arr[j] = arr[j + 1];
			n--, i--;
		}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}