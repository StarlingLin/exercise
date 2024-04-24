#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

namespace A
{
	int a = 10;
	void fun()
	{
		cout << "A::fun()" << endl;
	}
}

namespace B
{
	int a = 20;
	void fun()
	{
		cout << "B::fun()" << endl;
	}

	namespace C
	{
		int a = 30;
		void fun()
		{
			cout << "C::fun()" << endl;
		}
	
	}
}

int main()
{
	cout << A::a << endl;
	cout << B::a << endl;
	cout << B::C::a << endl;

	A::fun();
	B::fun();
	B::C::fun();

	return 0;
}