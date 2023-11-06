#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>

void sortofup(int s[], int n)/*n数组长度*/
{
	_Bool flag = true;
	while (flag)
	{
		flag = false;
		for (int i = 0; i < n - 1; i++)
			if (s[i] > s[i + 1])
			{
				s[i] ^= s[i + 1];
				s[i + 1] ^= s[i];
				s[i] ^= s[i + 1];/*交换*/
				flag = true;
			}
	}
}