#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	auto a = 1;
	auto b = 3.14;
	auto c = {1, 2};
	auto d = "hello world";
	auto e = 'c';

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;

	return 0;
}