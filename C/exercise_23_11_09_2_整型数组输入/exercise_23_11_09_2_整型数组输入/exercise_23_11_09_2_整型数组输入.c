#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

int n = 0, tem = 0, arr[666] = { 0 };
while ((tem = getchar()) != '\n')
{
	if (isdigit(tem))
	{
		ungetc(tem, stdin);
		scanf("%d", &arr[n++]);
	}
}