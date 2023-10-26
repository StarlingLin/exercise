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



//大佬的解法如下：
//#include<stdio.h>
//#include<stdlib.h>
////利用输出特性，或新建第三个数组存放数据，原理相同
//int main() {
//    int* arr1;//数组
//    int* arr2;
//    int m = 0, n = 0;//个数
//    int i = 0;
//    int f1 = 0, f2 = 0;//浮标
//    scanf("%d %d", &m, &n);
//    arr1 = (int*)malloc(sizeof(int) * (m + 1));//根据n的大小来规定数组的大小
//    arr2 = (int*)malloc(sizeof(int) * (n + 1));
//    for (i = 0; i < m; i++) {//输入数组
//        scanf("%d", &arr1[i]);
//    }
//    for (i = 0; i < n; i++) {//输入数组
//        scanf("%d", &arr2[i]);
//    }
//    i = 0;
//    while (i < (m + n)) {
//        if (f1 == m) {//第一个数组遍历完结，第二个还未完时
//            //这里可以不加"&&（f2<n)",若判断到f1==m时，f2必然是小于等于n的；
//            //这是由i控制的，i最大到n+m就决定了自增不会超过这个数即打印不会越界
//            printf("%d ", arr2[f2++]);//接着打印第二个数组剩余数
//        }
//        else if (f2 == n) {//同上
//            printf("%d ", arr1[f1++]);
//        }
//        else if (arr1[f1] >= arr2[f2]) {//打印小的数或相同数
//            printf("%d ", arr2[f2++]);
//        }
//        else if (arr1[f1] <= arr2[f2]) {
//            printf("%d ", arr1[f1++]);
//        }
//        i++;
//    }
//    return 0;
//}