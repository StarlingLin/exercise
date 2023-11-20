#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int len = sizeof arr / sizeof arr[0];
	int p = 0, q = 0;
	_Bool flag = true;
	
	for (int i = 0; i < len; i++)
	{
		flag = true;
		for (int j = 0; j < len; j++)
		{
			if (arr[i] == arr[j] && j != i)
			{
				flag = false;
				break;
			}
		}
		if (flag && (0 == p))
			p = arr[i];
		else if (flag && (p != 0) && (p != i))
			q = arr[i];
	}

	printf("%d %d\n", p, q);
	return 0;
}