#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//class A
//{
//public:
//	A(int a)
//	{
//		this->m_a = a;
//	}
//
//	void print1()
//	{
//		cout << "a" << endl;
//	}
//
//	void print2()
//	{
//		cout << "a = " << m_a << endl;
//	}
//
//private:
//	int m_a;
//};
//
//int main()
//{
//	A* a = new A(10);
//	//A* a = nullptr;
//	a->print2();
//	return 0;
//}

//�������Ĭ�ϳ�Ա����
//1.���캯��
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		m_year = year;
//		m_month = month;
//		m_day = day;
//	}
//
//	void print()
//	{
//		cout << m_year << "-" << m_month << "-" << m_day << endl;
//	}
//
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
//int main()
//{
//	Date d1;
//	d1.print();
//
//	Date d2(2020, 4, 30);
//	d2.print();
//
//	return 0;
//}

//2.��������
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		m_year = year;
//		m_month = month;
//		m_day = day;
//	}
//
//	~Date()
//	{
//		cout << "��������" << endl;
//	}
//
//	void print()
//	{
//		cout << m_year << "-" << m_month << "-" << m_day << endl;
//	}
//
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//};
//
//int main()
//{
//	Date d1;
//	d1.print();
//
//	Date d2(2020, 4, 30);
//	d2.print();
//
//	return 0;
//}

//3.�������캯��
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	Date(const Date& d)
	{
		m_year = d.m_year;
		m_month = d.m_month;
		m_day = d.m_day;
	}

	void print()
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	Date d1;
	d1.print();

	Date d2(2020, 4, 30);
	d2.print();

	Date d3(d2);
	d3.print();

	return 0;
}

//4.������ֵ�����
//5.�ƶ����캯��
//6.�ƶ���ֵ�����
