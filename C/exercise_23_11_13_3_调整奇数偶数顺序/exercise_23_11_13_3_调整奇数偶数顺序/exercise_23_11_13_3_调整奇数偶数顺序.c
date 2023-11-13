#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", *(arr + i));
}

void Adjust(int* arr, int len)
{
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (int i = 0; i < len - 1; i++)
		{
			if (0 == arr[i] % 2 && 1 == arr[i + 1] % 2)
			{
				arr[i] ^= arr[i + 1], arr[i + 1] ^= arr[i], arr[i] ^= arr[i + 1];
				flag = 1;
			}
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,5,4,7,9,8,0,11,22,12,17 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Adjust(arr, len);
	Print(arr, len);
	return 0;
}