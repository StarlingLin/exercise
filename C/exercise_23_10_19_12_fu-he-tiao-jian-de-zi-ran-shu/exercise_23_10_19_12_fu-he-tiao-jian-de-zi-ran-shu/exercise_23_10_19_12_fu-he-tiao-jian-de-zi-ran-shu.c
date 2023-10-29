#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int data = 0;

	scanf("%d", &data);

	for (int i = 0; i < data; i++)
	{
		if (i % 11 == 0)
		{
			printf("%d", i);
			if (i <= (data - 11))
				printf(" ");
		}
	}

	return 0;
}