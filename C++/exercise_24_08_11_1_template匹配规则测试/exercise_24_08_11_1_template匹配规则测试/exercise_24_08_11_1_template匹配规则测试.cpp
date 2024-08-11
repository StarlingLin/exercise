#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int f(int a, int b)
{
	return a + b + 1;
}

template <typename T>
T f(T a, T b)
{
	return a + b;
}

int main()
{
	cout << f(1, 2) << endl;
	cout << f<int>(1, 2) << endl;
	
	return 0;
}