#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int a = 0;//全局变量-储存在内存静态区

int main()
{
	{
		int a = 114514;//局部变量只影响其作用域内
	}
	int a = 1;//局部变量-储存在内存栈区
	printf("%d", a);//优先输出局部变量
	return 0;
}