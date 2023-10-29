#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

void maopao(int p[], int n) //冒泡排序，并打印比较次数和移动次数
{
	_Bool flag = false;
	int cnt1 = 0;
	int cnt2 = 0;
	int swi = 0;

	do
	{
		flag = false;
		for (int i = 0; i < n - 1; i++)
		{
			if (p[i], p[i + 1])
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