#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>

struct S1
{
	char ch;
	long double ldb;
	int n;
};

struct S2
{
	char ch;
	struct S1 s1;
	int n;
};

int main()
{
	printf("%zd\n", offsetof(struct S1, ch));
	printf("%zd\n", offsetof(struct S1, ldb));
	printf("%zd\n", offsetof(struct S1, n));
	printf("%zd\n", offsetof(struct S2, ch));
	printf("%zd\n", offsetof(struct S2, s1));
	printf("%zd\n", offsetof(struct S2, n));

	return 0;
}