#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>   //��ӡ�Գ�ͼ�ο��Լ�����þ���ֵ����

int main()
{
	char ch = 0;

	scanf("%c", &ch);

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= (int)fabs(3 - i); j++)
			printf(" ");

		for (int k = 1; k <= 5 - 2 * (int)fabs(3 - i); k++)
			printf("%c", ch);
		
		printf("\n");
	}

	return 0;
}