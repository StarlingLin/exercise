#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int n = 0;
	int arr[10][10] = { 0 };
	_Bool flag = false;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);
	for (int i = 0; i < n; i++)
	{
		flag = false;
		for (int j = 0; j < n; j++)
		{
			if (flag)
				printf(" ");
			printf("%d", arr[j][i]);
			flag = true;
		}
		printf("\n");
	}
	return 0;
}