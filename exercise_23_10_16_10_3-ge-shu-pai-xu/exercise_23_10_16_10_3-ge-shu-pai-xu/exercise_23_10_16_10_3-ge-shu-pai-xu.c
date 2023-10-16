#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a, b, c, l;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		l = a;
		a = b;
		b = l;
	}
	if (a < c)
	{
		l = a;
		a = c;
		c = l;
	}
	if (b < c)
	{
		l = b;
		b = c;
		c = l;
	}
	printf("%d %d %d", a, b, c);
	return 0;
}