#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	printf("\a\n");//警报
	printf("\?\n");//问号
	printf("\'\n");//'
	printf("\"\n");//"
	printf("\\\n");/*  \  */
	printf("a\ba\n");//退格
	printf("a\fa\n");//换页
	printf("a\na\n");//换行
	printf("a\ra\n");//回车
	printf("a\ta\n");//水平制表符
	printf("a\va\n");//垂直制表符
	printf("\130\n");//8进制ASCII
	printf("\x90\n");//16进制ASCII
	return 0;
}