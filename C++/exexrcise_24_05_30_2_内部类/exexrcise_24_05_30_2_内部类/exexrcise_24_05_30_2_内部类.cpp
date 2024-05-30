#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

//class Date
//{
//public:
//	Date(int y, int m, int d)
//		: m_year(y)
//		, m_month(m)
//		, m_day(d)
//	{}
//
//	void show()
//	{
//		cout << m_year << "-" << m_month << "-" << m_day << endl;
//	}
//
//private:
//	int m_year;
//	int m_month;
//	int m_day;
//
//	class Time
//	{
//	public:
//		Time(int h, int m, int s)
//			: m_hour(h)
//			, m_minute(m)
//			, m_second(s)
//		{}
//
//		void show()
//		{
//			cout << m_hour << ":" << m_minute << ":" << m_second << endl;
//			cout << m_year << "-" << m_month << "-" << m_day << endl;
//		}
//
//	private:
//		int m_hour;
//		int m_minute;
//		int m_second;
//	};
//};

class A
{
public:
	class B
	{
	public:
		void show(const A& AA)
		{
			cout << a << endl;
			cout << AA.b << endl;
		}
	};

private:
	static int a;
	int b;
};

int A::a = 10;

int main()
{
	A::B BB;
	BB.show(A());

	return 0;
}