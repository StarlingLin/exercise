#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		: m_year(year), m_month(month), m_day(day)
	{
	}

	int CountDays()
	{
		int days = 0;
		int monthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		for (int i = 0; i < m_month - 1; i++)
		{
			days += monthDays[i];
		}
		days += m_day;
		if (m_month > 2 && ((m_year % 4 == 0 && m_year % 100 != 0) || m_year % 400 == 0))
		{
			days++;
		}
		return days;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

int main()
{
	int year, month, day;
	while (cin >> year >> month >> day)
	{
		Date date(year, month, day);
		cout << date.CountDays() << endl;
	}

	return 0;
}