#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memset(void* p, int val, size_t n)
{
	assert(p && val);
	while (n--)
	{
		*(char*)p = val;
		((char*)p)++;
	}
}

int main()
{
	char str[] = "My name is LiHua.";
	//memset(str + 11, 'x', 5);
	my_memset(str + 11, 'x', 5);
	printf("%s", str);
	return 0;
}