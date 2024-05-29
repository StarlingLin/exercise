#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A
{
public:
    A() { ++m_cnt; }
    A(const A& t) { ++m_cnt; }
    ~A() { --m_cnt; }
    static int GetCnt() { return m_cnt; }
    static int m_cnt;
};

int A::m_cnt = 0;

int main()
{
	cout << A::GetCnt() << endl;
	A a1;
	A a2(a1);
	A a3(a2);
	A a4, a5, a6;
	cout << A::GetCnt() << endl;
	return 0;
}