#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

//С��

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
	
	//����
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

	//β��
	php->data[php->size++] = x;

	//���ϵ���
	AdjustUp(php->data, php->size-1);
}