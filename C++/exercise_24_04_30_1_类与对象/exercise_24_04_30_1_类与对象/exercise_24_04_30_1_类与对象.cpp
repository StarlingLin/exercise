#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A
{
public:
	A(int a)
	{
		this->m_a = a;
	}

	void print1()
	{
		cout << "a" << endl;
	}

	void print2()
	{
		cout << "a = " << m_a << endl;
	}

private:
	int m_a;
};

int main()
{
	A* a = new A(10);
	//A* a = nullptr;
	a->print2();
	return 0;
}