#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

void IsPrime(int p)
{
	_Bool flag = true;

	for (int i = 2; i < p; i++)
	{
		if (0 == p % i)
		{
			flag = false;
			break;
		}
	 }

	switch (flag)
	{
	case true: printf("Y"); break;
	case false: printf("N"); break;
	}
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	IsPrime(num);
	return 0;
}