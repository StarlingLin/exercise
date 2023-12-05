#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

enum Color
{
	RED = 4,
	GREEN = 2,
	BLUE = 1
};

enum Sex
{
	MALE,	//0
	FEMALE,	//1
	OTHER	//2
};

int main()
{
	enum Color clr = GREEN;
	clr = 2;//C:ok;C++:err	C++类型检查比较严格

	return 0;
}