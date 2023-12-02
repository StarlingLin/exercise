#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

union U
{
	char c;
	int n;
} uu;

union U1
{
	char c[5];
	int i;
}; 

union U2
{
	short s[7];
	int i;
};

int main()
{
	printf("%zd\n", sizeof(union U));  
	printf("%zd\n", sizeof(uu.c));  
	printf("%zd\n", sizeof(uu.n));  
	printf("%p\n", &uu);
	printf("%p\n", &(uu.c));
	printf("%p\n", &(uu.n));
	printf("%zd\n", sizeof(union U1));
	printf("%zd\n", sizeof(union U2));

	return 0;
}