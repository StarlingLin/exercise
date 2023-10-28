#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int IsLeapYear(int n)
{
	if (n > 0 && (0 == n % 4 && 0 != n % 100 || 0 == n % 400))
		return 1;
	else if (n > 0)
		return 0;
	else
		return -1;
}

int main()
{
	int n = 0;
	while(scanf("%d", &n) != EOF)
	{
		switch (IsLeapYear(n))
		{
		case 1: printf("YES\n"); break;
		case 0: printf("NO\n"); break;
		case -1:printf("INPUT A POSITIVE NUMBER!\n"); break;
		}
	}
	return 0;
}