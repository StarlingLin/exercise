#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
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

int main()
{
	int s[] = { 1,2,3,5,7,4,6 }, n = 7;
	sortofup(s, n);
	for (int i = 0; i < n; i++) printf("%d ", s[i]);
	return 0;
}