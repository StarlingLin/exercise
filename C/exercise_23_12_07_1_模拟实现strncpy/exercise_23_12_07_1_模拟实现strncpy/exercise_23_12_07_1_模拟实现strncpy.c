#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* my_strncpy(char* dest, const char* src, size_t n)
{
	assert(dest && src);
	char* ret = dest;
	while (n--)
		*dest++ = *src++;
	return ret;
}

int main()
{
	char s[] = "hauierhfuiehqw";
	char t[100] = { 0 };
	my_strncpy(t, s, 5);
	printf("%s", t);
	return 0;
}