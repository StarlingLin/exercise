#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	char arr1[] = "abc";
	char arr2[] = { 'a','b','c'};
	char arr3[] = { 'a','b','c','\0' };
	printf("%s\n",arr1);
	printf("%s\n",arr2);
	printf("%s\n",arr3);

	return 0;
}