#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	char c1;
	char c2;
	int i;
};

struct S3
{
	double d;
	char c;
	char i;
};

struct S4
{
	char c1;
	struct S3 s3;
	char d;
};

int main()
{
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	printf("%d\n", sizeof(struct S3));
	printf("%d\n", sizeof(struct S4));
	return 0;
}