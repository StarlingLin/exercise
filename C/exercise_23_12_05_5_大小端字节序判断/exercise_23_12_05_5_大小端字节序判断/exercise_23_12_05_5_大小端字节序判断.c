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
		printf("该机器为小端字节序机器\n");
	else
		printf("该机器为大端字节序机器\n");
	return 0;
}