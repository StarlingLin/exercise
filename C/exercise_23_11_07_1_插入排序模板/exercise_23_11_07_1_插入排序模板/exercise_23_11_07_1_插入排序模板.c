#define _CRT_SECURE_NO_WARNINGS 1

void sortofinsert(int n, int a[])
{
	int i, j, k, r;
	for (i = 1; i < n; i++)
	{/*�ŵ�i��Ԫ��*/
		while (j = i - 1, (a[j] > a[i]) && (j >= 0))
			j--;/*��λ��*/
		r = a[i];/*��¼a[i]*/
		for (k = i - 1; k >= j + 1; k--)
			a[k + 1] = a[k];/*����*/
		a[j + 1] = r;/*a[i]����*/
	}
}