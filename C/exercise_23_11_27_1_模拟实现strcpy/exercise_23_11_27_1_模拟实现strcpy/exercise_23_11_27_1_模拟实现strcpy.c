#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* my_strcpy(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest++ = *src++);
	return ret;
}

int main()
{
	char s[] = "hauierhfuiehqw";
	char t[100];
	my_strcpy(t, s);
	printf("%s", t);
	return 0;
}