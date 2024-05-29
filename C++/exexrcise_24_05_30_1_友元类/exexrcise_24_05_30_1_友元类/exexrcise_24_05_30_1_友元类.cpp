#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
	friend class Time;

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
};

class Time
{
public:
	Time(int h, int m, int s, int y, int month, int d)
		: m_hour(h)
		, m_minute(m)
		, m_second(s)
		, m_date(y, month, d)
	{}

	void show()
	{
		cout << m_hour << ":" << m_minute << ":" << m_second << endl;
		m_date.show();
	}

private:
	int m_hour;
	int m_minute;
	int m_second;
	Date m_date;
};

int main()
{
	Time t(12, 23, 34, 2020, 5, 30);
	t.show();

	return 0;
}