#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int num[3] = { 0 };
	
	for (int i = 0; i < 3; i++)
		scanf("%d", &num[i]);
	
	printf("%d", num[1]);
	
	return 0;
}