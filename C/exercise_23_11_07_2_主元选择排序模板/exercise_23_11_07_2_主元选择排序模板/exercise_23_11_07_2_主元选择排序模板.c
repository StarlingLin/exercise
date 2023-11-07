#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>

void sortofchoose(int n, int a[])
{
	for (int r, i = 0; i < n - 1; i++)
	{
		int j = i;
		for (int k = i + 1; k < n; k++)
			if (a[k] < a[j])
				j = k;
		r = a[i], a[i] = a[j], a[j] = r;
	}
}

//int main()
//{
//	int a[10] = { 0,2,9,4,1,8,6,3,7,5 }, n = 10;
//	sortofchoose(n, a);
//	for (int i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//}