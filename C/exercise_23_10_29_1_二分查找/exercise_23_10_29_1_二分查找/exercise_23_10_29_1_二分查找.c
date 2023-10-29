#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int bin_search(int arr[], int left, int right, int key)
{
	int i;
	int j = 1;
	do
	{
		i = (right + left) / 2;
		if (key > arr[i])
			left = i;
		else
			right = i;
	} while (arr[i] != key);
	return i;
}

int main()
{
	int left = 0;
	int right = 0;
	int key = 0;
	int arr[] = {1,2,3,4,55,66,777,888,999,1145,141919,810000,999999,1919810,314159265};

	printf("Input: left, right, key\n");
	scanf("%d%d%d", &left, &right, &key);

	printf("%d出现在区间中且下标为%d\n",key , bin_search(arr, left, right, key));

	return 0;
}