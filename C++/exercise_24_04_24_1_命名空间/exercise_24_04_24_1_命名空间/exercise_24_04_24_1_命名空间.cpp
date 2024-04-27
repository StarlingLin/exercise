#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//int a = 6;
//
//namespace A
//{
//	int a = 10;
//	void fun()
//	{
//		cout << "A::fun()" << endl;
//	}
//}
//
//namespace B
//{
//	int a = 20;
//	void fun()
//	{
//		cout << "B::fun()" << endl;
//	}
//
//	namespace C
//	{
//		int a = 30;
//		void fun()
//		{
//			cout << "C::fun()" << endl;
//		}
//	
//	}
//}
//
//int main()
//{
//	cout << a << endl;
//	cout << ::a << endl;
//	cout << A::a << endl;
//	cout << B::a << endl;
//	cout << B::C::a << endl;
//
//	A::fun();
//	B::fun();
//	B::C::fun();
//
//	return 0;
//}

//int a;
//
//namespace ExampleSpace1
//{
//	int a;
//	int b;
//}
//
//namespace ExampleSpace2
//{
//	int c;
//	namespace ExampleSpace3
//	{
//		int d;
//	}
//}

//using ExampleSpace1::b;
//
//int main()
//{
//	cout << b << endl;
//	return 0;
//}

//using namespace ExampleSpace2;
//
//int main()
//{
//	cout << ExampleSpace3::d << endl;
//	return 0;
//}

//int main()
//{
//	if (true)
//	{
//		using namespace ExampleSpace2::ExampleSpace3;
//		cout << d << endl;
//	}
//}

//int a = 0;
//
//namespace X
//{
//	int a = 10;
//}
//
//int main()
//{
//	if (true)
//	{
//		using namespace X;
//		cout << a << endl;	//err
//	}
//}