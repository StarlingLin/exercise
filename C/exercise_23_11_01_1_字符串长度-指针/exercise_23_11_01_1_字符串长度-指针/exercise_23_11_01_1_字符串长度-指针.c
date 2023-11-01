#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int strlen(char* str)
{
	int cnt = 0;
	while (str[cnt] != '\0')
		cnt++;
	return cnt;
}

int main()
{
	char str[1000] = { 0 };
	scanf("%[^\n]", str);
	printf("%d", strlen(str));
	return 0;
}