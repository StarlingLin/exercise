#pragma once

#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
} Heap;

void HeapInit(Heap* php);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
HPDataType HeapTop(Heap* php);
void HeapPop(Heap* php);	//É¾³ý¶Ñ¶¥ÔªËØ
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);