#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int nb(int arr[100], int n, int s)  //计算从arr[0]到arr[s]中有几对数成n倍关系
{
	int cnt = 0;

	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			if (arr[i] == arr[j] * n)
				cnt++;
	
	return cnt;
}

int main()
{
	int n = 0;
	int arr[100] = { 0 };
	int k = 0;
	int s = 0;

	scanf("%d", &n);

	for (int j = 0; k != -1; j++)
	{
		k = 1;
		for (int i = 0; k > 0; i++)
		{
			scanf("%d", &arr[i]);
			k = arr[i];
			s = i - 1;
		}
		if (k != -1)
			printf("%d\n", nb(arr, n, s));
	}
	return 0;
}