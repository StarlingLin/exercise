#pragma once

//��ӡ����
void PrintArray(int* a, int n);

//����
void Swap(int* a, int* b);

//��������
//ֱ�Ӳ�������
void InsertSort(int* arr, int n);
//ϣ������
void ShellSort(int* arr, int n);

//ѡ������
//ѡ������
void SelectSort(int* arr, int n);
//������
void HeapSort(int* arr, int n);

//��������
//ð������
void BubbleSort(int* arr, int n);
//��������
void QuickSort(int* arr, int left, int right);
void QuickSortRandomKey(int* arr, int left, int right);
void QuickSortMidKey(int* arr, int left, int right);
void QuickSortOptimized(int* arr, int left, int right);
void QuickSortDigHole(int* arr, int left, int right);
void QuickSortPrevCur(int* arr, int left, int right);
void QuickSortNonR(int* arr, int left, int right);

//�鲢����
void MergeSort(int* arr, int n);
