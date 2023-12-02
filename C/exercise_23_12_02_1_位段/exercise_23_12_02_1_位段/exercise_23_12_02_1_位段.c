#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct S
{
	int _a : 1;
	int _b : 2;
	int _c : 3;
	int _d : 4;
} s1;

int main()
{
	printf("%zd", sizeof(struct S));
	//&s1._a;//err

	return 0;
}