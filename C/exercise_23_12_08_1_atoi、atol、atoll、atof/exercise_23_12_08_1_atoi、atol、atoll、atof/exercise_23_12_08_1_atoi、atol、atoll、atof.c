#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char s[] = "  -1145141919810fiufw";
	char t[] = "  -114514.191981e5hhiul";

	double f = atof(t);
	int n = atoi(s);
	long m = atol(s);
	long long p = atoll(s);
	printf("%lf\n", f);
	printf("%d\n", n);
	printf("%ld\n", m);
	printf("%lld\n", p);
	return 0;
}