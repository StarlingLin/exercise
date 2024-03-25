#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_HEAP
//#define MAX_HEAP

#ifdef MIN_HEAP
#define HEAP_COMPARE(a, b) ((a) < (b))
#endif // MIN_HEAP - 寻找前k个最大值
#ifdef MAX_HEAP
#define HEAP_COMPARE(a, b) ((a) > (b))
#endif // MAX_HEAP - 寻找前k个最小值

void AdjustDown(int* arr, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && HEAP_COMPARE(arr[child + 1], arr[child]))
		{
			++child;
		}
		if (HEAP_COMPARE(arr[child], arr[parent]))
		{
			int temp = arr[child];
			arr[child] = arr[parent];
			arr[parent] = temp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void CreateNDate()
{
	// 造数据
	int n = 10000;
	srand((unsigned int)time(NULL));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}

	for (size_t i = 0; i < n; ++i)
	{
		int x = rand();
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void PrintTopK(int k)
{
	FILE* fin = fopen("data.txt", "r");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	int val = 0;
	int* arr = (int*)malloc(sizeof(int) * k);
	if (arr == NULL)
	{
		perror("malloc error");
		return;
	}
	for (int i = 0; i < k; ++i)
	{
		fscanf(fin, "%d", &val);
		arr[i] = val;
	}
	//前k个数建堆
	for (int i = (k - 2) / 2; i >= 0; --i)
	{
		AdjustDown(arr, k, i);
	}
	int x = 0;
	while (fscanf(fin, "%d", &x) != EOF)
	{
		if (!HEAP_COMPARE(x, arr[0]))
		{
			arr[0] = x;
			AdjustDown(arr, k, 0);
		}
	}
	for (int i = 0; i < k; ++i)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	int k = 0;
	printf("请输入要找的前k个数：");
	scanf("%d", &k);
	CreateNDate();
	PrintTopK(k);
	return 0;
}