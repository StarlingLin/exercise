#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int a = 0;
	_Bool flag = false;   
//ע�����ò������Ϳ�����һ�������м�����ض��ַ�������һ�����ǰ�����һ����ֺ󲻰����ַ�

	scanf("%d", &a);

	if (a % 3 == 0)
	{
		printf("3");
		flag = true;
	}

	if (a % 5 == 0)
	{
		if (flag)
			printf(",");
		printf("5");
		flag = true;
	}

	if (a % 7 == 0)
	{
		if (flag)
			printf(",");
		printf("7");
	}

	if (a % 3 != 0 && a % 5 != 0 && a % 7 != 0)
		printf("NULL");

	return 0;
}