#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int ret = 0;

void Reverse(int* f, int* l)
{
	if (f >= l)
		return;
	else
		*f ^= *l;
		*l ^= *f;
		*f ^= *l;
		Reverse(f + 1, l - 1);
}

int main()
{
	int n = 0, arr[100] = { 0 }, flag = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	Reverse(arr, arr + n - 1);
	for (int i = 0; i < n; i++)
	{
		if (flag)
			printf(" ");
		printf("%d", arr[i]);
		flag = 1;
		
	}
	return 0;
}