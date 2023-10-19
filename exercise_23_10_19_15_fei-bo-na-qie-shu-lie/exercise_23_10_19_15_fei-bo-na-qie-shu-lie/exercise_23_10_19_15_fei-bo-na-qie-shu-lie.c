#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int f = 0;
	long long feb1 = 1;
	long long feb2 = 1;
	long long m = 0;

	scanf("%d", &f);

	if (0 == f || 1 == f)
		printf("1");
	else
	{
		for (int i = 2; i <= f; i++)
		{
			m = feb2;
			feb2 = feb1 + feb2;
			feb1 = m;
		}

		printf("%lld", feb2);
	}

	return 0;
}