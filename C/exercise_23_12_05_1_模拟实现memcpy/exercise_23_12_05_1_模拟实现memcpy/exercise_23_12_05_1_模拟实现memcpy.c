#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memcpy(void* dest, const void* src, size_t n)
{
	assert(dest && src);
	void* ret = dest;
	while (n--)
	{
		*(char*)dest = *(char*)src;
		((char*)dest)++, ((char*)src)++;
	}
	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };
	//memcpy(arr2, arr1, 20);
	my_memcpy(arr2, arr1, 20);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr2[i]);
	return 0;
}