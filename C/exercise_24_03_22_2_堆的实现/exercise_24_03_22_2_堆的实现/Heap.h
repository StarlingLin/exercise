#pragma once

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define HEAP_TYPE 0	//0��ʾС�ѣ�1��ʾ���

#if HEAP_TYPE == 0
	#define HEAP_COMPARE(a, b) ((a) < (b))
#elif HEAP_TYPE == 1
	#define HEAP_COMPARE(a, b) ((a) > (b))
#endif // HEAP_TYPE = 0


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
void HeapPop(Heap* php);	//ɾ���Ѷ�Ԫ��
int HeapSize(Heap* php);
int HeapEmpty(Heap* php);