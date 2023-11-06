#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 114, b = 514;
	
	////1
	//int c = 0;
	//c = a;
	//a = b;
	//b = c;

	////2
	//a = b + a;
	//b = a - b;
	//a = a - b;

	//3
	a ^= b;
	b ^= a;
	a ^= b;

	printf("%d %d\n", a, b);
	return 0;
}