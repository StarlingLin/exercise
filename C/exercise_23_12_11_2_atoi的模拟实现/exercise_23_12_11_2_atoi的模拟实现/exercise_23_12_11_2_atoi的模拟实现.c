#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

int my_atoi(const char* str)
{
	assert(str);
	int ret = 0, sign = 1, flag = 1;
	while (isspace(*str++));
	str -= 2;
	while (isdigit(*++str) || '-' == *str && flag || '+' == *str && flag)
		if (*str == '-')
			flag = 0, sign = -1;
		else if (*str == '+')
			flag = 0, sign = 1;
		else
			flag = 0, ret = 10 * (ret + *str - '0');
	
	return sign * ret / 10;
}

int main()
{
	char str[] = "	 -114514";
	int ret = my_atoi(str);
	printf("%d", ret);
	return 0;
}