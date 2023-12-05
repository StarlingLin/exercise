#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

int my_memcmp(const void* p1, const void* p2, size_t n)
{
	assert(p1 && p2);
	while (n--)
	{
		if (*(char*)p1 > *(char*)p2)
			return 1;
		if (*(char*)p1 < *(char*)p2)
			return -1;
		((char*)p1)++, ((char*)p2)++;
	}
	return 0;
}

int main()
{
	char s1[] = "QWERtyuIOP";
	char s2[] = "QWERtYuIoP";
	printf("%d\n", memcmp(s1, s2, sizeof(s1)));
	printf("%d\n", my_memcmp(s1, s2, sizeof(s1)));
	return 0;
}