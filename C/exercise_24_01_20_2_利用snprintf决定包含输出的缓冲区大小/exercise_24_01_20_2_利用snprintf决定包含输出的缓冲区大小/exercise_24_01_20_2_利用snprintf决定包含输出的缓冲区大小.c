#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	const char* format = "sqrt(2) = %f";
	int sz = snprintf(NULL, 0, format, sqrt(2));
	char* buf = (char*)malloc(sz + 1);	// +1 for '\0'
	snprintf(buf, sz + 1, format, sqrt(2));
	printf("%s\n", buf);

	return 0;
}