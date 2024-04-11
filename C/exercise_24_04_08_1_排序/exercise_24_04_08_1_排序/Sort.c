#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Sort.h"
#include "Stack.h"

//��ӡ����
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//����
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//��������
//ֱ�Ӳ�������
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
//ϣ������
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

//ѡ������
//ѡ������
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
//������
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

//��������
//ð������
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
//��������
////////////////////////////////////////////////
/*hoare����*/
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
/*���ѡkey�Ż�*/
void QuickSortRandomKey(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;

	//���������������λ������λ����
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
/*����ȡ�з��Ż�*/
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

	//����ȡ��
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
/*С�����Ż�*/
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

		//����ȡ��
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
/*�ڿӷ�*/
void QuickSortDigHole(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int key = left, begin = left, end = right;
	int tmp = arr[key];	//�ڿ�
	while (left < right)
	{
		while (left < right && arr[right] >= tmp)
		{
			--right;
		}
		arr[left] = arr[right];	//��ʱ��λ����߱�Ϊ�ұ�
		while (left < right && arr[left] <= tmp)
		{
			++left;
		}
		arr[right] = arr[left];	//��ʱ��λ���ұ߱�Ϊ���
	}
	arr[left] = tmp;
	QuickSort(arr, begin, left - 1);
	QuickSort(arr, left + 1, end);
}
////////////////////////////////////////////////
/*ǰ��ָ�뷨*/
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
/*�ǵݹ����*/
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

//�鲢����
