#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int CommonDivisor(int a, int b)
{
	int c = 0;//����
	int c2 = 0;//��һ����2�Ĵ���
	int r = 0;//������������
	int cd = 0;//���

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