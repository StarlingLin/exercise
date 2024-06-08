#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10, b = 20;
	cout << "a = " << a << ", b = " << b << endl;
	Swap<int>(a, b);
	cout << "a = " << a << ", b = " << b << endl;

	double c = 1.1, d = 2.2;
	cout << "c = " << c << ", d = " << d << endl;
	Swap(c, d);
	cout << "c = " << c << ", d = " << d << endl;

	double e = 1.1, f = 2.2;
	cout << "e = " << e << ", f = " << f << endl;
	Swap(e, f);
	cout << "e = " << e << ", f = " << f << endl;

	return 0;
}