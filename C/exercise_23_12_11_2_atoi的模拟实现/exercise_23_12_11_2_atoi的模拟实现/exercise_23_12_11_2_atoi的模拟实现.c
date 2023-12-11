#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int my_atoi(char* str)
{
	assert(str);
	int ret = 0, sign = 1;
	while (isspace(*str++));
	str -= 2;
	while (isdigit(*++str) || '-' == *str)
		if (*str == '-')
			sign = -1;
		else
			ret = 10 * (ret + *str - '0');
	
	return sign * ret / 10;
}

int main()
{
	char str[] = "	 -114514eiolwf";
	int ret = my_atoi(str);
	printf("%d", ret);
	return 0;
}