#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int check_sys()
{
	int i = 1;
	return *(char*)&i;
}

int main()
{
	if (check_sys())
		printf("�û���ΪС���ֽ������\n");
	else
		printf("�û���Ϊ����ֽ������\n");
	return 0;
}