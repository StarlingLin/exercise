#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int my_strlen(char arr[])
{
	int i = 0;
	while (*(arr + i))
		i++;
	return i;
}

int main()
{
	char ch[] = "114514abcdef !@#$";
	printf("%d", my_strlen(ch));
	return 0;
}