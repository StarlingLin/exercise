#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item
{
    //公共属性
    int number;    //数量
    double price;    //定价
    int type;    //类型

    //私有属性
    union
    {
        struct
        {
            char title[20];    //书名
            char author[20];    //作者
            int pages;    //⻚数
        } book;

        struct
        {
            char design[30];    //设计
        } cup;

        struct
        {
            char design[30];    //设计
            int colors;    //颜⾊
            int sizes;    //尺⼨
        } shirt;
    } item;
} i;

int main()
{
    strcpy(i.item.book.author, "114514");

    return 0;
}

//union Un1
//{
//	char c[5];
//	int i;
//};
//
//union Un2
//{
//	short c[7];
//	int i;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(union Un1));
//	printf("%d\n", sizeof(union Un2));
//	return 0;
//}

//#include <stdio.h>
//
//union Un
//{
//	char c;
//	int i;
//};
//
//int main()
//{
//	union Un un = { 0 };
//	un.i = 0x11223344;
//	un.c = 0x55;
//	printf("%x\n", un.i);
//	return 0;
//}
//
////int main()
////{
////	union Un un = { 0 };
////	printf("%d\n", sizeof(un));
////	return 0;
////}