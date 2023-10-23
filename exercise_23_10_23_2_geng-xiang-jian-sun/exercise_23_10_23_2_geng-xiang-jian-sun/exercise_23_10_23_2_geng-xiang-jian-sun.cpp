#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int CommonDivisor(int a, int b)
{
	int c = 0;//余数
	int c2 = 0;//第一步除2的次数
	int r = 0;//交换数过渡区
	int cd = 0;//结果

	while (0 == a % 2 && 0 == b % 2)
	{
		a /= 2;
		b /= 2;
		c2++;
	}

	while (a != b)
	{
		if (a < b)
		{
			r = a;
			a = b;
			b = r;
		}

		c = a - b;
		a = b;
		b = c;
		c = 0;
	}

	cd = (int)pow(2, c2) * a;

	return cd;
}

int main()
{
	int m = 1;
	int n = 1;

	while (scanf("%d%d", &m, &n) != EOF && m != 0 && n != 0)
		printf("%d\n", CommonDivisor(m, n));

	return 0;
}