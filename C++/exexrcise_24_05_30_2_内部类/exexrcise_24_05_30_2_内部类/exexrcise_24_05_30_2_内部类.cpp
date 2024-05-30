#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int y, int m, int d)
		: m_year(y)
		, m_month(m)
		, m_day(d)
	{}

	void show()
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}

private:
	int m_year;
	int m_month;
	int m_day;

	class Time
	{
	public:
		Time(int hh, int mm, int ss, int y, int m, int d)
			: m_hour(hh)
			, m_minute(mm)
			, m_second(ss)
			, m_date(y, m, d)
		{}

		void show(const Date& dd)
		{
			cout << m_hour << ":" << m_minute << ":" << m_second << endl;
			cout << dd.m_year << "-" << dd.m_month << "-" << dd.m_day << endl;
		}

	private:
		int m_hour;
		int m_minute;
		int m_second;
	};
};

//class A
//{
//public:
//	class B
//	{
//	public:
//		void show(const A& AA)
//		{
//			cout << a << endl;
//			cout << AA.b << endl;
//		}
//	};
//
//private:
//	static int a;
//	int b;
//};
//
//int A::a = 10;

int main()
{
	//A::B BB;
	//BB.show(A());

	Date::Time t(10, 20, 30, 2020, 5, 30);	//err - 一个类在其自身完整定义之前不能实例化其自身的对象

	return 0;
}