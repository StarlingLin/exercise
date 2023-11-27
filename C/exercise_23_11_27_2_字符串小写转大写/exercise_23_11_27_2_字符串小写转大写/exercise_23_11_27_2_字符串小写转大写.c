#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

char* caps(char* s)
{
	char* ret = s;
	do
	{
		if (islower(*s))
			*s = toupper(*s);
	} while (*s++);
	return ret;
}

int main()
{
	char s[] = "ajiofe";
	printf("%s\n", caps(s));
	return 0;
}