#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void swi(int a, int b)
{
	
}

void zhuyuan(int p[]) //主元选择排序，打印比较次数和移动次数
{
	int ser = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < 9; i++)
	{
		int min = p[i];
		for (int j = i + 1; j < 10; j++)
		{
			if (min > p[j])
			{
				min = p[j];
				ser = j;
			}
			cnt1++;
		}
		p[ser] = p[i];
		p[i] = min;
		cnt2++;
	}

	printf("%d %d ", cnt1, cnt2);
}

void maopao(int p[]) //冒泡排序，打印比较次数和移动次数
{
	_Bool flag = false;
	int cnt1 = 0;
	int cnt2 = 0;
	int swi = 0;

	do
	{
		flag = false;
		for (int i = 0; i < 9; i++)
		{
			if (p[i] > p[i + 1])
			{
				swi = p[i + 1];
				p[i + 1] = p[i];
				p[i] = swi;
				flag = true;
				cnt2++;
			}
			cnt1++;
		}
	} while (flag);

	printf("%d %d ", cnt1, cnt2);
}

void charu(int p[]) //插入排序，打印比较次数和移动次数
{
	int cnt1 = 0;
	int cnt2 = 0;
	int swi = 0;

	for (int i = 1; i < 10; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (p[j - 1] > p[j])
			{
				swi = p[j];
				p[j] = p[j - 1];
				p[j - 1] = swi;
				cnt1++;
				cnt2++;
			}
			else
			{
				cnt1++;
				break;
			}

		}
	}

	printf("%d %d ", cnt1, cnt2);
}

int main()
{
	int arr0[11] = { 0 };
	int arr[11] = { 0 };

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr0[i]);
	}

	memcpy(arr, arr0, sizeof(arr0));
	zhuyuan(arr);
	memcpy(arr, arr0, sizeof(arr0));
	maopao(arr);
	memcpy(arr, arr0, sizeof(arr0));
	charu(arr);
	printf("\b");

	return 0;
}