#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct S
{
	int data[3];
	int num;
} s = { {1,2,3}, 1000 };

void print1(struct S s)
{
	printf("%d\n", s.num);
}

void print2(struct S* ps)
{
	printf("%d\n", ps->num);
}

int main()
{
	print1(s); //���ṹ��
	print2(&s); //����ַ
	return 0;
}