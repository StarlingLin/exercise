#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	int k = 0;
	
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (i != 9 && arr[i] > arr[k])
			k = i;
	}

	printf("max = %d",arr[k]);

	return 0;
}