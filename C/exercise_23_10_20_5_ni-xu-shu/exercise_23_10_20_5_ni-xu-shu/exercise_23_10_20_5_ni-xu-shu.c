#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	long long a = 0;
	_Bool flag = false;

	scanf("%lld", &a);

	if (a >= 0)
	{
		while (a != 0)
		{
			if (a % 10 != 0 || flag)
				printf("%lld", a % 10);
			a /= 10;
			flag = true;
		}
	}
	else
		printf("NULL");

	return 0;
}