#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

namespace X
{
	void print(int n)
	{
		cout << "X: " << n << endl;
	}
}

using namespace X;

void print(int n)	//与X::print(int n)形成重载，但是如果直接调用会造成调用歧义报错
{
	cout << n << endl;
}

void print(const char* s)
{
	cout << s << endl;
}

void print(int n, double d)
{
	cout << n << ", " << d << endl;
}

void print(double d, int n = 5)
{
	cout << d << ", " << n << endl;
}

void print(double d)	//与上一个函数形成重载，但是只有一个参数时，会造成调用歧义报错
{
	cout << d << endl;
}

int main()
{
	//print(10);	//err
	//print(3.14);	//err
	print(3.14, 5);
	print("Hello, C++");
	print(10, 3.14);
	print(3.14, 10);

	return 0;
}