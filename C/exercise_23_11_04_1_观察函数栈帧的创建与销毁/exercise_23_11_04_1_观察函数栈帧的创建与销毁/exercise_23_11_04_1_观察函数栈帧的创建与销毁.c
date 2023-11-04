#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Add(int x, int y)
{
	int sum = 0;
	sum = x + y;
	return sum;
}//Ğ´µÄÏêÏ¸±ãÓÚ¹Û²ì

int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	printf("%d", c);
	return 0;
}