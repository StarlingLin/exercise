#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int n = 9;
	float* p = (float*)&n;
	printf("n的值为：%d\n", n);
	printf("*p的值为：%f\n", *p);
	
	*p = 9.0;
	printf("n的值为：%d\n", n);
	printf("*p的值为：%f\n", *p);
	
	return 0;
}