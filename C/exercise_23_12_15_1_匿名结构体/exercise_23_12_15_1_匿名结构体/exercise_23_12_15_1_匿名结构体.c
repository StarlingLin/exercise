#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct
{
	int a;
	long b;
	float c;
} x;

struct
{
	int a;
	long b;
	float c;
} y, *p;

typedef struct
{
	int a;
	long b;
	float c;
} stct;

int main()
{
	//*p = &x;	//err
	stct s_a = {.b = 1, .a = 3, .c = 2};

	return 0;
}