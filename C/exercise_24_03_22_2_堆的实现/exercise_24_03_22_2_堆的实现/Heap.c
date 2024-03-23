#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

//小堆

void HeapInit(Heap* php)
{
	assert(php);
	php->data = NULL;
	php->size = 0;
	php->capacity = 0;
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
		if (data[child] < data[parent])
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