#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	char* sign1 = (char*)str1;
	char* sign2 = (char*)str1;
	char* sign = (char*)str2;
	while (*sign1)
	{
		if (!*sign)
			return sign1;
		sign1++;
		sign2 = sign1;
		sign = (char*)str2;
		while (*sign2 && *sign && !(*sign2 - *sign))
			sign2++, sign++;
	}
	return NULL;
}

int main()
{
	char s1[] = "qwertyuiop";
	char s2[] = "wer";
	char* s = my_strstr(s1, s2);
	strncpy(s, "123", 3);
	printf("%s", s1);
	return 0;
}