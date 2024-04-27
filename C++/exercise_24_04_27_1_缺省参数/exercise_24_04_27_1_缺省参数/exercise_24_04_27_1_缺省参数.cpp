#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void func(int a, int b = 10, int c = 20);

void func(int a, int b, int c)
{
	cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main()
{
	func(1);
	func(1, 2);
	func(1, 2, 3);
	return 0;
}