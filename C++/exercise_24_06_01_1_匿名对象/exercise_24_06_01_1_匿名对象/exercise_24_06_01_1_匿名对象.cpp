#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class A
{
public:
    A(int k)
        : m_m(k)
    {}

    ~A() {}

    int GetSquare()
    {
        return m_m * m_m;
    }

private:
    int m_m;
};

void test()
{
    //有名对象计算平方
    A a(2);
    cout << a.GetSquare() << endl;

    //匿名对象计算平方
    cout << A(2).GetSquare() << endl;
}

int main()
{
    test();

    return 0;
}