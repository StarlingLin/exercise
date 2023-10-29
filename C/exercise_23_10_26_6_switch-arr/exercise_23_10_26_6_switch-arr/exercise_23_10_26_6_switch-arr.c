#define _CRT_SECURE_NO_WARNINGS 1

#include <string.h>

int main()
{
	int arr1[] = { 1,2,3 };
	int arr2[] = { 4,5,6 };
	int arrs[] = { 0 };

	memcpy(arrs, arr1, sizeof(arr1));
	memcpy(arr1, arr2, sizeof(arr1));
	memcpy(arr2, arrs, sizeof(arr1));
	return 0;
}