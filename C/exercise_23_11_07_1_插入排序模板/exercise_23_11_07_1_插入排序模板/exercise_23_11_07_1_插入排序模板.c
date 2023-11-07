#define _CRT_SECURE_NO_WARNINGS 1

void sortofinsert(int n, int a[])
{
	int i, j, k, r;
	for (i = 1; i < n; i++)
	{/*排第i个元素*/
		while (j = i - 1, (a[j] > a[i]) && (j >= 0))
			j--;/*找位置*/
		r = a[i];/*记录a[i]*/
		for (k = i - 1; k >= j + 1; k--)
			a[k + 1] = a[k];/*后移*/
		a[j + 1] = r;/*a[i]置入*/
	}
}