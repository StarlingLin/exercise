#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int Valid = 0, Invalid = 0;

void check(char* str, int b)
{
	_Bool flag = false;
	for (int i = 0; i < b; i++)
	{
		flag = false;
		if ((i == 0 && (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))) || (i != 0 && (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9'))))
			flag = true;
		else break;
	}
	if (flag)
		Valid++;
	else 
		Invalid++;
}

int main() 
{
	char str[666] = { 0 };
	int n = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) 
	{
		gets(str);
		check(str, strlen(str));
		memset(str, '\0', 666);
	}
	printf("Valid:%d\nInvalid:%d", Valid, Invalid);
}
