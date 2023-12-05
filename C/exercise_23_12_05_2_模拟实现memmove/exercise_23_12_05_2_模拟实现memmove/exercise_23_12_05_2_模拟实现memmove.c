#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>

void* my_memmove(void* dest, const void* src, size_t n)
{
	assert(dest && src);
	void* ret = dest;
	if (dest <= src)
	{
		while (n--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)++, ((char*)src)++;
		}
	}
	else
	{
		dest = (char*)dest + n - 1;
		src = (char*)src + n - 1;
		while (n--)
		{
			*(char*)dest = *(char*)src;
			((char*)dest)--, ((char*)src)--;
		}
	}
	return ret;
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//memmove(arr + 2, arr, 20);
	my_memmove(arr + 2, arr, 20);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr[i]);
	return 0;
}