#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

#pragma pack(1)//设置默认对⻬数为1

struct S
{
	char c1;
	int i;
	char c2;
};

#pragma pack()//取消设置的对⻬数，还原为默认

int main()
{
	printf("%d\n", sizeof(struct S));
	return 0;
}