#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int num;
void print(int a[], int n)
{
	int i;
	printf("%d=%d", num, a[0]);
	for (i = 1; i <= n; i++) printf("+%d", a[i]);
	printf("\n");
	return;
}/*�������*/
int check(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] < a[i + 1]) return 0;
	}
	return 1;
}/*�ж��Ƿ�Ϊ����*/

void lines(int n, int a[], int tot)
{

	int i, j, k;
	for (i = n - 1; i > 0; i--)
	{
		j = n - i;
		a[tot] = i; a[tot + 1] = j;/*����ֵ����洢�����������*/
		if (check(a, tot + 1)) print(a, tot + 1);
		if (j > 1) {
			lines(j, a, tot + 1);
		}
	}
}

int main()
{
	scanf("%d", &num);
	int* a = (int*)malloc(num*sizeof(int));
	lines(num, a, 0);
	return 0;
}

