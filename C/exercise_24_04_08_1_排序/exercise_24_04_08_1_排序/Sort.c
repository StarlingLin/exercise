#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include "Stack.h"

//打印数组
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//交换
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//插入排序
//直接插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (tmp < arr[end])
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}
//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (tmp < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
}

//选择排序
//选择排序
void SelectSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			Swap(&arr[i], &arr[min]);
		}
	}
}
//堆排序
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
	for (int i = n / 2 - 1; i >= 0; --i)
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

//交换排序
//冒泡排序
void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 0;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
//快速排序
////////////////////////////////////////////////
/*hoare快排*/
void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			--right;
		}
		while (left < right && arr[left] <= arr[key])
		{
			++left;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[left], &arr[key]);
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}
////////////////////////////////////////////////
/*随机选key优化*/
void QuickSortRandomKey(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;

	//生成随机数并将该位置与首位调换
	int random = rand() % (right - left + 1) + left;
	Swap(&arr[random], &arr[left]);

	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			--right;
		}
		while (left < right && arr[left] <= arr[key])
		{
			++left;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[left], &arr[key]);
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}
////////////////////////////////////////////////
/*三数取中法优化*/
int GetMid(int* arr, int left, int right)
{
	int center = (left + right) / 2;
	if (arr[left] > arr[center])
	{
		Swap(&arr[left], &arr[center]);
	}
	if (arr[left] > arr[right])
	{
		Swap(&arr[left], &arr[right]);
	}
	if (arr[left] > arr[center])
	{
		Swap(&arr[center], &arr[right]);
	}
	return arr[center];
}
void QuickSortMidKey(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;

	//三数取中
	int mid = GetMid(arr, left, right);
	Swap(&arr[mid], &arr[left]);

	while (left < right)
	{
		while (left < right && arr[right] >= arr[key])
		{
			--right;
		}
		while (left < right && arr[left] <= arr[key])
		{
			++left;
		}
		Swap(&arr[left], &arr[right]);
	}
	Swap(&arr[left], &arr[key]);
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}
////////////////////////////////////////////////
/*小区间优化*/
void QuickSortOptimized(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left < 10)
	{
		InsertSort(arr + left, right - left + 1);
	}
	else
	{
		int key = left, begin = left, end = right;

		//三数取中
		int mid = GetMid(arr, left, right);
		Swap(&arr[mid], &arr[left]);

		while (left < right)
		{
			while (left < right && arr[right] >= arr[key])
			{
				--right;
			}
			while (left < right && arr[left] <= arr[key])
			{
				++left;
			}
			Swap(&arr[left], &arr[right]);
		}
		Swap(&arr[left], &arr[key]);
		QuickSort(arr, begin, left - 1);
		QuickSort(arr, left + 1, end);
	}
}
////////////////////////////////////////////////
/*挖坑法*/
void QuickSortDigHole(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;
	int tmp = arr[key];	//挖坑
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
		{
			--right;
		}
		arr[left] = arr[right];	//此时坑位从左边变为右边
		while (left < right && arr[left] <= tmp)
		{
			++left;
		}
		arr[right] = arr[left];	//此时坑位从右边变为左边
	}
	arr[left] = tmp;
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}
////////////////////////////////////////////////
/*前后指针法*/
void QuickSortPrevCur(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;
	int prev = left, cur = left + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[key] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		++cur;
	}
	Swap(&arr[prev], &arr[key]);
	key = prev;
	//[begin, key - 1] [key] [key + 1, end]
	QuickSort(arr, begin, key - 1);
	QuickSort(arr, key + 1, end);
}
////////////////////////////////////////////////
/*非递归快排*/
void QuickSortNonR(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	Stack st;
	InitStack(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		int key = begin;
		int prev = begin, cur = begin + 1;
		while (cur <= end)
		{
			if (arr[cur] < arr[key] && ++prev != cur)
			{
				Swap(&arr[prev], &arr[cur]);
			}
			++cur;
		}
		Swap(&arr[prev], &arr[key]);
		key = prev;
		//[begin, key - 1] [key] [key + 1, end]
		if (begin < key - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, key - 1);
		}
		if (key + 1 < end)
		{
			StackPush(&st, key + 1);
			StackPush(&st, end);
		}
	}
	StackDestory(&st);
}
////////////////////////////////////////////////

//归并排序
