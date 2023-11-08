#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

void charu(int p[])//插入排序，打印比较次数和移动次数
{
	int cnt1 = 0;
	int cnt2 = 0;
	int j = 0;
	int swi = 0;
	_Bool flag = false;
	for (int i = 1; i < 10; i++)
	{
		flag = false;
		j = i - 1;
		while (cnt1++, j >= 0 && p[i] < p[j])
		{
			j--;
			flag = true;
		}
		swi = p[i];
		for (int k = i - 1; k >= j + 1; k--)
		{
			p[k + 1] = p[k];
			if (flag)
				cnt2++;
		}
		p[j + 1] = swi;
		if (flag)
			cnt2++;
	}
}