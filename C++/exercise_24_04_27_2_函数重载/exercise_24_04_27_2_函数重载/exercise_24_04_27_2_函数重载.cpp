#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//void print(int a) 
//{
//	cout << "int: " << a << endl;
//}
//
//void print(double a)
//{
//	cout << "double: " << a << endl;
//}
//
//void print(char a)
//{
//	cout << "char: " << a << endl;
//}
//
//int main()
//{
//	print(10);
//	print(10.5);
//	print('A');
//
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	return n;
//}
//
//int main()
//{
//	int a = Count();
//	int b = Count();
//	int c = Count();
//
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//
//	return 0;
//}

//int& getElement(int* array, int index)
//{
//	return array[index];  // 返回数组元素的引用
//}
//
//int main()
//{
//	int arr[3] = { 1, 2, 3 };
//	getElement(arr, 0) = 4;  // 通过引用修改数组元素
//	cout << arr[0] << endl;  // 输出 4
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);
//	cout << "Add(1,2) is: " << ret << endl;
//	return 0;
//}

#include <time.h>

struct A
{ 
	int a[10000]; 
};

A a;

A TestFunc1() { return a; }
A& TestFunc2() { return a; }

int main()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (size_t i = 0; i < 1000000; ++i)
		TestFunc2();
	size_t end2 = clock();
	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1 time:" << end1 - begin1 << endl;
	cout << "TestFunc2 time:" << end2 - begin2 << endl;

	return 0;
}