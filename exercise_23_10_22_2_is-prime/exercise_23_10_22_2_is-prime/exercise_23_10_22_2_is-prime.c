#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

_Bool IsPrime(int p)
{
	_Bool flag = true;

	for (int i = 2; i <= sqrt(p); i++)
		if (0 == p % i)
		{
			flag = false;
			break;
		}

	return flag;
}

int main()
{
	for (int j = 100; j <= 200; j++)
		if (IsPrime(j))
			printf("%d ", j);

	return 0;
}