#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int check_sys()
//{
//	int i = 1;
//	return *(char*)&i;
//}

int check_sys()
{
	union
	{
		int i;
		char c;
	} u;
	u.i = 1;
	return u.c;
}

int main()
{
	int a = 0x12345678;
	if (check_sys())
		printf("�û���ΪС���ֽ������\n");
	else
		printf("�û���Ϊ����ֽ������\n");
	return 0;
}