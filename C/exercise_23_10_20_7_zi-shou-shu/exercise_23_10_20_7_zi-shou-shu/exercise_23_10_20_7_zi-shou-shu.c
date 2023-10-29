#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

//int main()
//{
//	long n = 0;
//	_Bool flag = false;
//
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; i++)
//	{		
//		for (int zs = 1; zs <= (int)log10(pow(i, 2)) + 1; zs++)  //注意数字长度可以用(int)log10()表示
//			if ((int)pow(i, 2) % (int)pow(10, (int)log10(i) + 1) == i)
//			{
//				if (flag)
//					printf(" ");
//				printf("%d", i);
//				break;
//			}
//
//		flag = true;
//	}
//
//	return 0;
//}

int main()
{
	long long n = 0;
	_Bool flag = false;

	scanf("%lld", &n);

	for (int i = 1; i <= n; i++)
	{
		if ((long long)pow(i, 2) % (long long)pow(10, (int)log10(i) + 1) == i)//注意数字长度可以用(int)log10()表示
		{
			if (flag)
				printf(" ");
			printf("%lld", i);
		}

		flag = true;
	}

	return 0;
}