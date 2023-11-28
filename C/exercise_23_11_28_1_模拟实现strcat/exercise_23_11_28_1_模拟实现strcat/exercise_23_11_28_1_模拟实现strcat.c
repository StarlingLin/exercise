#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	while (*++dest);
	while (*dest++ = *src++);
	return dest;
}

int main()
{
	char s1[100] = "114514";
	char s2[] = "1919810";
	my_strcat(s1, s2);
	printf("%s", s1);
	return 0;
}