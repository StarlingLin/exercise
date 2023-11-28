#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (!*str1)
			return 0;
		str1++, str2++;
	}
	return *str1 - *str2;

}

int main()
{
	char s1[] = "1124";
	char s2[] = "1123";
	printf("%d", my_strcmp(s1, s2));
	return 0;
}