#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void HeapInit(Heap* php)
{
	assert(php);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HeapInitArr(Heap* php, HPDataType* a, int n)
{
	assert(php);
	php->data = (HPDataType*)malloc(n * sizeof(HPDataType));
	if (php->data == NULL)
	{
		perror("malloc fail\n");
		exit(EXIT_FAILURE);
	}
	memcpy(php->data, a, n * sizeof(HPDataType));
	php->size = php->capacity = n;

	//向下调整
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(php->data, php->size, i);
	}
}

void HeapDestory(Heap* php)
{
	assert(php);
	free(php->data);
	php->data = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

void AdjustUp(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (HEAP_COMPARE(data[child], data[parent]))
		{
			Swap(&data[child], &data[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	
	//扩容
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 6 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->data, newcapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail\n");
			exit(EXIT_FAILURE);
		}
		php->data = tmp;
		php->capacity = newcapacity;
	}

	//尾插
	php->data[php->size++] = x;

	//向上调整
	AdjustUp(php->data, php->size-1);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	return php->data[0];
}

void AdjustDown(HPDataType* data, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && HEAP_COMPARE(data[child + 1], data[child]))
		{
			++child;
		}
		if (HEAP_COMPARE(data[child], data[parent]))
		{
			Swap(&data[child], &data[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->data[0], &php->data[php->size - 1]);
	--php->size;
	AdjustDown(php->data, php->size, 0);
}

int HeapSize(Heap* php)
{
	assert(php);
	return php->size;
}

int HeapEmpty(Heap* php)
{
	assert(php);
	return php->size == 0;
}