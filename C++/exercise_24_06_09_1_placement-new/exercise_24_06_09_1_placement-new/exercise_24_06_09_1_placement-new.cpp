#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A
{
public:
	A(int a = 0)
		: m_a(a)
	{
		cout << "A()" << this << endl;
	}

	~A()
	{
		cout << "~A()" << this << endl;
	}

private:
	int m_a;
};

int main()
{
	A* p1 = (A*)malloc(sizeof(A));
	new (p1) A;
	p1->~A();
	free(p1);

	A* p2 = (A*)operator new(sizeof(A));
	new (p2) A(10);
	p2->~A();
	operator delete(p2);

	return 0;
}