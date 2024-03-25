#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define MIN_HEAP
#define MAX_HEAP

#ifdef MIN_HEAP
#define HEAP_COMPARE(a, b) ((a) < (b))
#endif // MIN_HEAP - ������ɴ�С
#ifdef MAX_HEAP
#define HEAP_COMPARE(a, b) ((a) > (b))
#endif // MAX_HEAP - �������С����

typedef int HPDataType;

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

void HeapSort(HPDataType* a, int n)
{
	//����
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//����
	for (int i = 0; i < n; ++i)
	{
		Swap(&a[0], &a[n - 1 - i]);
		AdjustDown(a, n - 1 - i, 0);
	}
}

//����
int main()
{
	printf("������Ҫ��������ָ�����");
	int n;
	scanf("%d", &n);
	HPDataType* a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	//�ļ�����
	FILE* fp = fopen("data.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		fscanf(fp, "%d", &a[i]);
	}
	fclose(fp);

	HeapSort(a, n);

	//�ļ����
	fp = fopen("output.txt", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		fprintf(fp, "%d\n", a[i]);
	}
	fclose(fp);

	free(a);
	return EXIT_SUCCESS;
}

////���������
//int main()
//{
//	srand((unsigned int)time(NULL));
//	printf("������Ҫ���ɵ������������");
//	int n;
//	scanf("%d", &n);
//	
//	FILE* fp = fopen("data.txt", "w");
//	if (fp == NULL)
//	{
//		printf("�ļ���ʧ��\n");
//		return 0;
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		fprintf(fp, "%d\n", rand());
//	}
//	fclose(fp);
//
//	return EXIT_SUCCESS;
//}