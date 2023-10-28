#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int lennum(int n)   //获取数字位数
{
	return (int)log10((double)n) + 1;
}

void gap(int i, int j, int n)   //控制算式间隙保证格式
{
	int a = lennum(i) + lennum(j) + lennum(i * j) + 2;  //该算式长度
	int b = 2 * lennum(n) + lennum(n * n) + 2;  //本次最大算式长度
	for (int k = 1; k <= (b - a + 2); k++)  //打印差值+2那么多空格
		printf(" ");
}

void table(int n)  //打印乘法口诀表
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d×%d=%d", i, j, i * j);
			gap(i, j, n);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	table(n);
	return 0;
}