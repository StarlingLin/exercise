#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a, b, c;
	a = 5;
	c = ++a;
	b = ++c, c++, ++a, a++;//������Ӱ��b��������
	b += a++ + c;
	printf("a = %d b = %d c = %d\n:", a, b, c);
	return 0;
}