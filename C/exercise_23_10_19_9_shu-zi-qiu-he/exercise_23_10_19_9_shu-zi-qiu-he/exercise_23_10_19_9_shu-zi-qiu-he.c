#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	int x = 0;
	int sum = 0;

	scanf("%d", &a);

	for (int i = 1; i <= 5; i++)
	{
		scanf("%d", &x);
		if (0 == x % a)
			sum += x;
	}

	printf("%d", sum);

	return 0;
}