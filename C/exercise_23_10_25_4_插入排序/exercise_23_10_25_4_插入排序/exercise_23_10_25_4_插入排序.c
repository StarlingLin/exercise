#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void charu(int p[], int n) //插入排序，并打印比较次数和移动次数
{
	int cnt1 = 0;
	int cnt2 = 0;
	int swi = 0;

	for (int i = 1; i < n; i++)
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