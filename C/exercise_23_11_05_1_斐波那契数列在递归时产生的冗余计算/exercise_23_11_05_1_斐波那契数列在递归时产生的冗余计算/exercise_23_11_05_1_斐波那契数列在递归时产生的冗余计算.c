#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
long long count = 0;
int Fib(int n)
{
	if (n == 2)
		count++;
	if (n <= 2)
		return 1;
	else
		return Fib(n - 1) + Fib(n - 2);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fib(n);
	printf("%d\n", ret);
	printf("\ncount = %lld\n", count);
	return 0;
}