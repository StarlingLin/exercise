#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	short n = 0;
	_Bool flag = false;

	scanf("%hd", &n);

	for (short i = 1; i <= n; i++)
	{
		if (flag)
			printf("\n");
		
		for (short j = 1; j <= n - i; j++)
			printf("  ");

		for (short p = 1; p <= i; p++)
		{
			if (p != 10)
				printf("%2hd", p);
			else
				printf(" 0");
		}

		for (short k = 1; k <= i - 1; k++)
		{
			printf("%2hd", i - k);
		}
		
		flag = true;
	}

	return 0;
}