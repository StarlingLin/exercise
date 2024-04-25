#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void print(int n)
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

int main()
{
	print(10);
	print(3.14);
	print("Hello, C++");
	print(10, 3.14);
	print(3.14, 10);

	return 0;
}