#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

int lennum(int n)   //��ȡ����λ��
{
	return (int)log10((double)n) + 1;
}

void gap(int i, int j, int n)   //������ʽ��϶��֤��ʽ
{
	int a = lennum(i) + lennum(j) + lennum(i * j) + 2;  //����ʽ����
	int b = 2 * lennum(n) + lennum(n * n) + 2;  //���������ʽ����
	for (int k = 1; k <= (b - a + 2); k++)  //��ӡ��ֵ+2��ô��ո�
		printf(" ");
}

void table(int n)  //��ӡ�˷��ھ���
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d��%d=%d", i, j, i * j);
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