#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Heap.h"

int main()
{
	int a[] = { 123, 890, 234, 232, 121, 890, 888, 111 };
	Heap hp;
	HeapInit(&hp);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		HeapPush(&hp, a[i]);
	}
	HeapDestory(&hp);
	return EXIT_SUCCESS;
}