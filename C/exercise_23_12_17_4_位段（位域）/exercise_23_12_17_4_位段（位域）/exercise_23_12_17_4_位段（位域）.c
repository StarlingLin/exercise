#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct A
{
	int _a : 2;
	int _b : 5;
	int _c : 10;
	int _d : 30;
}; 

struct B
{
	int _a : 2, _b : 5,  _c : 10;
	int _d;
};

struct C
{
	unsigned _a : 2;
	signed _b : 5;
	int _c : 30, _d : 1, _e : 3;
	int _f : 3, : 2, _g : 4;
}; 

struct D
{
	unsigned _a : 2, :0;
	signed _b : 5, :0;
	int _c : 30, _d : 1, _e : 3;
	int _f : 3, : 2, _g : 4;
};

int main()
{
	printf("%d\n", sizeof(struct A));
	printf("%d\n", sizeof(struct B));
	printf("%d\n", sizeof(struct C));
	printf("%d\n", sizeof(struct D));
	return 0;
}