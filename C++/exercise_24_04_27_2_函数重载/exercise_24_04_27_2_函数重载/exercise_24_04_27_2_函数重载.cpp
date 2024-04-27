#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void print(int a) 
{
	cout << "int: " << a << endl;
}

void print(double a)
{
	cout << "double: " << a << endl;
}

void print(char a)
{
	cout << "char: " << a << endl;
}

int main()
{
	print(10);
	print(10.5);
	print('A');

	return 0;
}