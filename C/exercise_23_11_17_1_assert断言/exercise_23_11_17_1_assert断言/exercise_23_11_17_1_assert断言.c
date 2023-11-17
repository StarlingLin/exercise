#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int main()
{
	int n = 0;
	int* p = &n;
	p = NULL;
	assert(p != NULL);
	return 0;
}