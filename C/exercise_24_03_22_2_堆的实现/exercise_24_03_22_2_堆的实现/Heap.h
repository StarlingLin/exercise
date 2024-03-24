#pragma once

#include <stdlib.h>
#include <string.h>
#include <assert.h>

//#define MIN_HEAP
#define MAX_HEAP

#ifdef MIN_HEAP
	#define HEAP_COMPARE(a, b) ((a) < (b))
#endif // MIN_HEAP
#ifdef MAX_HEAP
	#define HEAP_COMPARE(a, b) ((a) > (b))
#endif // MAX_HEAP

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int size;
	int capacity;
} Heap;

void HeapInit(Heap* php);
void HeapInitArr(Heap* php, HPDataType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
HPDataType HeapTop(Heap* php);
void HeapPop(Heap* php);	//É¾³ý¶Ñ¶¥ÔªËØ
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);

void Swap(HPDataType* a, HPDataType* b);
void AdjustDown(HPDataType* data, int size, int parent);
void AdjustUp(HPDataType* data, int child);