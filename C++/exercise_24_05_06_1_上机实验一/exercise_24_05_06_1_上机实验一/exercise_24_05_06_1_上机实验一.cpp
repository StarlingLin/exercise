#define _CRT_SECURE_NO_WARNINGS

/*
* 对如下多项式编写类定义：
* a_0 + a_1 * x + a_2 * x^2 + … + a_n * x^n
* 其中，n为多项式的次数。完成如下功能：
* - 可存储任意大的多项式。（顺序表）
* - 定义构造函数、析构函数、拷贝构造函数。
* - 包含一个static成员存储定义的多项式数量。
* - 定义一个成员函数输出多项式。（可参照-x^4-6x^3+5的格式输出，要化简）
* - 定义一个成员函数计算多项式的值。
* - 重载“+”“-”“*”运算符实现多项式的加减乘运算。
* - 重载“=”运算符实现赋值运算。
* - 在main函数编写测试代码。
* 要求采用多文件实现。
* 考虑哪些函数可以声明为const，把其中某个运算符重载为友元函数。
*/

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	double a1[] = { 1, 2, 3, 4, 5 };
	double a2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Polynomial p1(4, a1);
	Polynomial p2(9, a2);
	Polynomial p3(4, 1.1, 2.2, 3.3, 4.4, 5.5);
	Polynomial p4(p1);
	Polynomial p5 = p1 + p2;
	Polynomial p6 = p1 + p4;
	Polynomial p7 = p1 - p2;
	Polynomial p8 = p1 - p4;
	Polynomial p9 = p1 * p2;
	Polynomial p10 = p1 * p4;
	p1.print();
	p2.print();
	p3.print();
	p4.print();
	p5.print();
	p6.print();
	p7.print();
	p8.print();
	p9.print();
	p10.print();

	return 0;
}