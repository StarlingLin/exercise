#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void forward(int p[], int j, int n)
{
	for (int k = j; k < n - 1; k++)
		p[k] = p[k+1];
}

int main()
{
	_Bool flag = false;
	int n = 0;
	scanf("%d", &n);
	//int* arr = malloc(n * sizeof(int));
	//��д��vs�ܱ���ɹ�������ƨ����ѧϰͨ�����ұ���ʧ��
	int* arr;
	arr = (int*)malloc(n * sizeof(int));
	
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && arr[i] == arr[j])
			{
				forward(arr, j, n);
				n--, j--;
			}

	for (int i = 0; i < n; i++)
	{
		if (flag)
			printf(" ");
		printf("%d", arr[i]);
		flag = true;
	}
	return 0;
}