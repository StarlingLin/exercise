#pragma once

//´òÓ¡Êı×é
void PrintArray(int* a, int n);

//½»»»
void Swap(int* a, int* b);

//²åÈëÅÅĞò
//Ö±½Ó²åÈëÅÅĞò
void InsertSort(int* arr, int n);
//Ï£¶ûÅÅĞò
void ShellSort(int* arr, int n);

//Ñ¡ÔñÅÅĞò
//Ñ¡ÔñÅÅĞò
void SelectSort(int* arr, int n);
//¶ÑÅÅĞò
void HeapSort(int* arr, int n);

//½»»»ÅÅĞò
//Ã°ÅİÅÅĞò
void BubbleSort(int* arr, int n);
//¿ìËÙÅÅĞò
void QuickSort(int* arr, int left, int right);
void QuickSortRandomKey(int* arr, int left, int right);
void QuickSortMidKey(int* arr, int left, int right);
void QuickSortOptimized(int* arr, int left, int right);
void QuickSortDigHole(int* arr, int left, int right);
void QuickSortPrevCur(int* arr, int left, int right);
void QuickSortNonR(int* arr, int left, int right);

//¹é²¢ÅÅĞò
void MergeSort(int* arr, int n);
void MergeSortNonR(int* arr, int n);

//¼ÆÊıÅÅĞò
void CountSort(int* arr, int n);

//»ùÊıÅÅĞò
void RadixSort(int* arr, int n);

//Í°ÅÅĞò
void BucketSort(int* arr, int n);