#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int num = 114;
//    unsigned rnum = (unsigned)num;
//    int count = 0;//计数
//    while (rnum)
//    {
//        if (rnum % 2 == 1)
//            count++;
//        rnum /= 2;
//    }
//    printf("二进制中1个数 = %d\n", count);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int num = -1;
//    int i = 0;
//    int count = 0;//计数
//
//    for (i = 0; i < 32; i++)
//        if (num & (1 << i))//或者写成((num >> i) & 1)也一样
//            count++;
//    printf("二进制中1的个数= %d\n", count);
//    return 0;
//}

#include <stdio.h>

int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//计数
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("二进制中1的个数= %d\n", count);
	return 0;
}