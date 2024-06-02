#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}

	A(int x)
	{
		cout << "A constructor with parameter" << x << endl;
	}

	A(int x, int y)
	{
		cout << "A constructor with parameters" << x << "&" << y << endl;
	}

	~A()
	{
		cout << "A destructor" << endl;
	}
};

int main()
{
	A* a = new A;
	delete a;

	A* b = new A(1);
	delete b;

	A* c = new A(1, 2);
	delete c;

	A* d = new A[5]{ 1,2,3,{4,5} };
	delete[] d;

	return 0;
}