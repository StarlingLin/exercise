#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr1[1000] = { 0 };
	int arr2[1000] = { 0 };
	int arrans[2000] = { 0 };
	int m = 0;
	int n = 0;
	int a1 = 0;//mark
	int a2 = 0;
	int i = 0;

	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%d", &arr1[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr2[i]);

	while (a1 + a2 <= m + n)
	{
		if (arr1[a1] <= arr2[a2] && a1 != m || arr1[a1] > arr2[a2] && a2 == n)
		{
			arrans[i] = arr1[a1];
			i++, a1++;
		}
		else
		{
			arrans[i] = arr2[a2];
			i++, a2++;
		}
	}
	for (i = 0; i < m + n; i++)
		printf("%d ", arrans[i]);
	return 0;
}



//���еĽⷨ���£�
//#include<stdio.h>
//#include<stdlib.h>
////����������ԣ����½����������������ݣ�ԭ����ͬ
//int main() {
//    int* arr1;//����
//    int* arr2;
//    int m = 0, n = 0;//����
//    int i = 0;
//    int f1 = 0, f2 = 0;//����
//    scanf("%d %d", &m, &n);
//    arr1 = (int*)malloc(sizeof(int) * (m + 1));//����n�Ĵ�С���涨����Ĵ�С
//    arr2 = (int*)malloc(sizeof(int) * (n + 1));
//    for (i = 0; i < m; i++) {//��������
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < n; i++) {//��������
//        scanf("%d", &arr2[i]);
//    }
//    i = 0;
//    while (i < (m + n)) {
//        if (f1 == m) {//��һ�����������ᣬ�ڶ�����δ��ʱ
//            //������Բ���"&&��f2<n)",���жϵ�f1==mʱ��f2��Ȼ��С�ڵ���n�ģ�
//            //������i���Ƶģ�i���n+m�;������������ᳬ�����������ӡ����Խ��
//            printf("%d ", arr2[f2++]);//���Ŵ�ӡ�ڶ�������ʣ����
//        }
//        else if (f2 == n) {//ͬ��
//            printf("%d ", arr1[f1++]);
//        }
//        else if (arr1[f1] >= arr2[f2]) {//��ӡС��������ͬ��
//            printf("%d ", arr2[f2++]);
//        }
//        else if (arr1[f1] <= arr2[f2]) {
//            printf("%d ", arr1[f1++]);
//        }
//        i++;
//    }
//    return 0;
//}