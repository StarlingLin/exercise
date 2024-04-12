#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//
//int Comp_int(const void* a, const void* b)
//{
//	int ia = *(int*)a;
//	int ib = *(int*)b;
//	if (ia > ib)
//		return 1;
//	if (ia < ib)
//		return -1;
//	else
//		return 0;
//}
//
//int Comp_int2(const void* a, const void* b)
//{
//	int ia = *(int*)a;
//	int ib = *(int*)b;
//	if (ia < ib)
//		return 1;
//	if (ia > ib)
//		return -1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int n, m, *arr;
//	scanf("%d%d", &n, &m);
//	arr = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//	}
//	for (int j = 0; j < m; j++)
//	{
//		int p, q;
//		scanf("%d%d", &p, &q);
//		if (0 == p)
//		{
//			qsort(arr, q, sizeof(int), Comp_int2);
//		}
//		else if (1 == p)
//		{
//			qsort(arr + q - 1, n - q + 1, sizeof(int), Comp_int);
//		}
//	}
//	for (int k = 0; k < n; k++)
//	{
//		printf("%d ", arr[k]);
//	}
//	printf("\n");
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//
//void ShellSort(int* arr, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tmp > arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//}
//
//void ShellSort2(int* arr, int n)
//{
//	int gap = n;
//	while (gap > 1)
//	{
//		gap /= 2;
//		for (int i = 0; i < n - gap; ++i)
//		{
//			int end = i;
//			int tmp = arr[end + gap];
//			while (end >= 0)
//			{
//				if (tmp < arr[end])
//				{
//					arr[end + gap] = arr[end];
//					end -= gap;
//				}
//				else
//				{
//					break;
//				}
//			}
//			arr[end + gap] = tmp;
//		}
//	}
//}
//
//int main()
//{
//	int n, m, * arr;
//	scanf("%d%d", &n, &m);
//	arr = (int*)malloc(n * sizeof(int));
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = i + 1;
//	}
//	for (int j = 0; j < m; j++)
//	{
//		int p, q;
//		scanf("%d%d", &p, &q);
//		if (0 == p)
//		{
//			ShellSort(arr, q);
//		}
//		else if (1 == p)
//		{
//			ShellSort2(arr + q - 1, n - q + 1);
//		}
//	}
//	for (int k = 0; k < n; k++)
//	{
//		printf("%d ", arr[k]);
//	}
//	printf("\n");
//}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjustDown(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			++child;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* arr, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; --i)
	{
		AdjustDown(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, end, 0);
		--end;
	}
}
void AdjustDown2(int* arr, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && arr[child + 1] < arr[child])
		{
			++child;
		}
		if (arr[child] < arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort2(int* arr, int n)
{
	int i;
	for (i = n / 2 - 1; i >= 0; --i)
	{
		AdjustDown2(arr, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown2(arr, end, 0);
		--end;
	}
}
int main()
{
	int n, m, * arr;
	scanf("%d%d", &n, &m);
	arr = (int*)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	int j;
	for (j = 0; j < m; j++)
	{
		int p, q;
		scanf("%d%d", &p, &q);
		if (0 == p)
		{
			HeapSort2(arr, q);
		}
		else if (1 == p)
		{
			HeapSort(arr + q - 1, n - q + 1);
		}
	}
	int k;
	for (k = 0; k < n; k++)
	{
		printf("%d ", arr[k]);
	}
	printf("\n");
}