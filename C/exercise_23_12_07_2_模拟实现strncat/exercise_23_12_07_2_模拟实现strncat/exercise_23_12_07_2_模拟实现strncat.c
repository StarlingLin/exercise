#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

char* my_strncat(char* dest, const char* src, size_t n)
{
	assert(dest && src);
	char* ret = dest;
	while (*++dest);
	while (n--)
	{
		if (0 == *src)
			break;
		else
			*dest++ = *src++;
	}
	*dest = 0;
	return ret;
}

int main()
{
	char s1[100] = "114514";
	char s2[] = "1919810";
	my_strncat(s1, s2, 3
	);
	printf("%s", s1);
	return 0;
}