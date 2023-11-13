#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void Print(int* arr, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ", *(arr + i));
}

int main()
{
	int arr[] = { 1,1,4,5,1,4,1,9,1,9,8,1,0 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Print(arr, len);
	return 0;
}