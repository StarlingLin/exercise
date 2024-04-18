#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sort.h"

void TestInsertSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	PrintArray(arr, n);
}

void TestShellSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	ShellSort(arr, n);
	PrintArray(arr, n);
}

void TestSelectSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	SelectSort(arr, n);
	PrintArray(arr, n);
}

void TestHeapSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	PrintArray(arr, n);
}

void TestBubbleSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, n);
	PrintArray(arr, n);
}

void TestQuickSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSort(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortRandomKey()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortRandomKey(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortMidKey()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortMidKey(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortOptimized()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortOptimized(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortDigHole()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortDigHole(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortPrevCur()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortPrevCur(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestQuickSortNonR()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, n - 1);
	PrintArray(arr, n);
}

void TestMergeSort()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSort(arr, n);
	PrintArray(arr, n);
}

void TestMergeSortNonR()
{
	int arr[] = { 3, 9, 1, 4, 7, 5, 2, 8, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	MergeSortNonR(arr, n);
	PrintArray(arr, n);
}

void TestTime()
{
	srand((unsigned int)time(NULL));
	const int N = 10000000;
	int* arr1 = (int*)malloc(sizeof(int) * N);
	int* arr2 = (int*)malloc(sizeof(int) * N);
	int* arr3 = (int*)malloc(sizeof(int) * N);
	int* arr4 = (int*)malloc(sizeof(int) * N);
	int* arr5 = (int*)malloc(sizeof(int) * N);
	int* arr6 = (int*)malloc(sizeof(int) * N);
	int* arr7 = (int*)malloc(sizeof(int) * N);
	int* arr8 = (int*)malloc(sizeof(int) * N);
	int* arr9 = (int*)malloc(sizeof(int) * N);
	int* arr10 = (int*)malloc(sizeof(int) * N);
	int* arr11 = (int*)malloc(sizeof(int) * N);
	int* arr12 = (int*)malloc(sizeof(int) * N);
	int* arr13 = (int*)malloc(sizeof(int) * N);
	int* arr14 = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; ++i)
	{
		arr1[i] = rand();
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
		arr4[i] = arr1[i];
		arr5[i] = arr1[i];
		arr6[i] = arr1[i];
		arr7[i] = arr1[i];
		arr8[i] = arr1[i];
		arr9[i] = arr1[i];
		arr10[i] = arr1[i];
		arr11[i] = arr1[i];
		arr12[i] = arr1[i];
		arr13[i] = arr1[i];
		arr14[i] = arr1[i];
		
		//arr6[i] = i;
		//arr7[i] = i;
		//arr8[i] = i;
		//arr9[i] = i;
		//arr10[i] = i;
		//arr11[i] = i;
		//arr12[i] = i;
	}
	
	clock_t start = clock();
	//InsertSort(arr1, N);
	clock_t end = clock();
	printf("InsertSort:%d\n", end - start);
	free(arr1);

	start = clock();
	ShellSort(arr2, N);
	end = clock();
	printf("ShellSort:%d\n", end - start);
	free(arr2);

	start = clock();
	//SelectSort(arr3, N);
	end = clock();
	printf("SelectSort:%d\n", end - start);
	free(arr3);

	start = clock();
	HeapSort(arr4, N);
	end = clock();
	printf("HeapSort:%d\n", end - start);
	free(arr4);

	start = clock();
	//BubbleSort(arr5, N);
	end = clock();
	printf("BubbleSort:%d\n", end - start);
	free(arr5);

	start = clock();
	QuickSort(arr6, 0, N - 1);
	end = clock();
	printf("QuickSort:%d\n", end - start);
	//PrintArray(arr6, N);
	free(arr6);

	start = clock();
	QuickSortRandomKey(arr7, 0, N - 1);
	end = clock();
	printf("QuickSortRandomKey:%d\n", end - start);
	free(arr7);

	start = clock();
	QuickSortMidKey(arr8, 0, N - 1);
	end = clock();
	printf("QuickSortMidKey:%d\n", end - start);
	free(arr8);

	start = clock();
	QuickSortOptimized(arr9, 0, N - 1);
	end = clock();
	printf("QuickSortOptimized:%d\n", end - start);
	free(arr9);

	start = clock();
	QuickSortDigHole(arr10, 0, N - 1);
	end = clock();
	printf("QuickSortDigHole:%d\n", end - start);
	free(arr10);

	start = clock();
	QuickSortPrevCur(arr11, 0, N - 1);
	end = clock();
	printf("QuickSortPrevCur:%d\n", end - start);
	free(arr11);

	start = clock();
	QuickSortNonR(arr12, 0, N - 1);
	end = clock();
	printf("QuickSortNonR:%d\n", end - start);

	start = clock();
	MergeSort(arr13, N);
	end = clock();
	printf("MergeSort:%d\n", end - start);

	start = clock();
	MergeSortNonR(arr14, N);
	end = clock();
	printf("MergeSortNonR:%d\n", end - start);
}

int main()
{
	TestInsertSort();
	TestShellSort();
	TestSelectSort();
	TestHeapSort();
	TestBubbleSort();
	TestQuickSort();
	TestQuickSortRandomKey();
	TestQuickSortMidKey();
	TestQuickSortOptimized();
	TestQuickSortDigHole();
	TestQuickSortPrevCur();
	TestQuickSortNonR();
	TestMergeSort();
	TestMergeSortNonR();
	
	TestTime();
	return 0;
}
