#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

char* BF(const char* str1, const char* str2)
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

char* KMP(const char* str1, const char* str2)
{


}

int main()
{
	char str1[] = "ababcabcdabcde";
	char str2[] = "abcd";
	char* s = BF(str1, str2);
	strncpy(s, "@@@@", 4);
	printf("%s", str1);
	return 0;
}