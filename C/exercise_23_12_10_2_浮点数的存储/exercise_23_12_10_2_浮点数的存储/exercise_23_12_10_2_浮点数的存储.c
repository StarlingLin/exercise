#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int n = 9;
	float* p = (float*)&n;
	printf("n��ֵΪ��%d\n", n);
	printf("*p��ֵΪ��%f\n", *p);
	
	*p = 9.0;
	printf("n��ֵΪ��%d\n", n);
	printf("*p��ֵΪ��%f\n", *p);
	
	return 0;
}