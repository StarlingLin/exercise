#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main()
{
	int a = 0;
	_Bool flag = false;

	for (a = 100; a <= 999; a++)
	{
		if (a == pow(a % 10, 3) + pow(a % 100 / 10, 3) + pow(a / 100, 3))
		{
			if (flag)
				printf(" ");
			printf("%d", a);
			flag = true;
		}
	}

	return 0;
}