#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void Forward(char s[], size_t len)
{
	int temp = s[0];
	for (int i = 0; i < len - 1; i++)
		s[i] = s[i + 1];
	s[len - 1] = temp;
}

_Bool Same(char s1[], char s2[])
{
	for (int i = 0; i < strlen(s1); i++)
		if (s1[i] == s2[i])
			return true;
	return false;
}

int main()
{
	char s1[999] = { 0 }, s2[999] = { 0 };
	int ret = 0;
	gets(s1), gets(s2);
	for (int i = 0; s1 != s2 || i >= strlen(s1); Forward(s1, strlen(s1)), i++)
		if (Same(s1, s2))
		{
			ret = 1;
			break;
		}
	printf("%d\n", ret);
	//printf("%s\n%s\n", s1, s2);
	return 0;
}