#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void init(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		arr[i] = 0;
}

void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\b\n");
}

void reverse(int* arr, int n)
{
	int arrcpy[100] = { 0 };
	memcpy(arrcpy, arr, n * sizeof(int));
	for (int i = 0; i < n; i++)
		arr[i] = arrcpy[n - 1 - i];
}

void input(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[100] = { 0 };
	input(arr, n);
	reverse(arr, n);
	print(arr, n);
	init(arr, n);
	print(arr, n);

	return 0;
}