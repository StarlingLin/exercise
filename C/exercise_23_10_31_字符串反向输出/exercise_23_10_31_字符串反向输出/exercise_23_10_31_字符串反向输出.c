#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void reverse(char arr[], int n)
{
	int k = 0;
	for (int i = 0; i < (n + 1) / 2; i++)
		k = arr[i], arr[i] = arr[n - 1 - i], arr[n - 1 - i] = k;
}

int main()
{
	char arr[255] = { 0 };
	scanf("%[^\n]", arr);
	reverse(arr, strlen(arr));
	printf("%s", arr);
	return 0;
}

