#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Heap.h"

int main()
{
	int a[] = { 123, 890, 234, 232, 121, 890, 888, 111 };
	Heap hp;
	HeapInitArr(&hp, a, sizeof(a) / sizeof(a[0]));
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestory(&hp);
	return EXIT_SUCCESS;
}