#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>

_Bool Bigger(int a, int b)
{
	if (a > b)
		return true;
	else
		return false;
}

void zhuyuan(int p[], int n) //��Ԫѡ�����򣬲���ӡ�Ƚϴ������ƶ�����
{
	int ser = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int min = p[i];
		for (int j = i + 1; j < n; j++)
		{
			if (Bigger(min, p[j]))
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