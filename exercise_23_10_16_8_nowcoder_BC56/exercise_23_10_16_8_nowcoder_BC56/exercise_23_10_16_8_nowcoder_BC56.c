#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a , i;
	while (scanf("%d", &a) != EOF)
	{
		for (i = 0; i < a; i++)
			printf("*");
		printf("\n");
	}
	return 0;
}

//#include<stdio.h>
//int main()
//{
//    int a;
//    while (scanf("%d", &a) != EOF)
//    {
//        while (a > 0)
//        {
//            printf("*");
//            a--;
//        }
//        printf("\n");
//    }
//    return 0;
//}