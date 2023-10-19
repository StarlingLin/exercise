#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

int main()
{
	int a = 0;
	_Bool flag = false;   
//注意利用布尔类型可以让一列内容中间包含特定字符，而第一个组分前、最后一个组分后不包括字符

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