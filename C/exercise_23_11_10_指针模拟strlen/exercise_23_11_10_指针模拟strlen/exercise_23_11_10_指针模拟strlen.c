#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

//size_t my_strlen(const char arr[])
//{
//	assert(arr);
//	int i = 0;
//	while (*(arr + i))
//		i++;
//	return i;
//}

//size_t my_strlen(const char arr[])
//{
//	assert(arr);
//	return *(arr) ? 1 + my_strlen(arr + 1) : 0;
//}

size_t my_strlen(const char arr[])
{
	assert(arr);
	char* p = arr;
	while (*p)
		p++;
	return p - arr;
}

int main()
{
	char ch[100];
	gets(ch);
	printf("%d\n", my_strlen(ch));
	return 0;
}