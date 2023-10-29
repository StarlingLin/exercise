#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char ch = 0;

	scanf("%c", &ch);

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
			printf("%c", ch);
		printf("\n");
	}

	return 0;
}
