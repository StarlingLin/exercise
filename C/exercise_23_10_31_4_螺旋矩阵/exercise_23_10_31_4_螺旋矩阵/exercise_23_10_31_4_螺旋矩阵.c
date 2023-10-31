#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[30][30] = { 0 };
	int n = 0, i = 0, j = 0, cnt = 1, flag = 0;
	scanf("%d", &n);

	while (cnt <= n * n)
	{
		arr[i][j] = cnt;
		cnt++;

		switch (flag % 4)
		{
		case 0: 
			if (j < n - 1 && 0 == arr[i][j + 1])
				j++;
			else
				i++, flag++;
			break;
		case 1:
			if (i < n - 1 && 0 == arr[i + 1][j])
				i++;
			else
				j--, flag++;
			break;
		case 2:
			if (j > 0 && 0 == arr[i][j - 1])
				j--;
			else
				i--, flag++;
			break;
		case 3:
			if (i > 0 && 0 == arr[i - 1][j])
				i--;
			else
				j++, flag++;
			break;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%4d", arr[i][j]);
		printf("\n");
	}
	return 0;
}