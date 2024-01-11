#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct
{
	int x;
	struct
	{
		int y;
		union
		{
			int z;
			char c;
		};
	};
} a;

struct S1
{
	struct S2
	{
		union U1
		{
			union U2
			{
				int n1;
				int n2;
			} u2;
			int n3;
		} u1;
		int n4;
	} s2;
	int n5;
} s1;

int main()
{
	a.z = 1;
	s1.s2.u1.u2.n1 = 1;
	printf("%d\n", a.c);
	printf("%d\n", s1.s2.u1.n3);
	return 0; 
}