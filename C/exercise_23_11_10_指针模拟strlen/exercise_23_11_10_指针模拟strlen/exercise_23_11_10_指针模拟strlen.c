#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int my_strlen(const char arr[])
{
	assert(arr);
	int i = 0;
	while (*(arr + i))
		i++;
	return i;
}

int main()
{
	char ch[100];
	gets(ch);
	printf("%d\n", my_strlen(ch));
	return 0;
}