#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		: m_year(year)
		, m_month(month)
		, m_day(day)
	{}

	void display()
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}

	int GetMonthDay(int year, int month)
	{
		static int monthArray[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		{
			return 29;
		}
		return monthArray[month - 1];
	}

	Date& operator-=(int days)
	{
		while (days > 0)
		{
			if (days >= m_day)
			{
				days -= m_day;
				if (m_month == 1)
				{
					m_month = 12;
					m_year--;
				}
				else
				{
					m_month--;
				}
				m_day = GetMonthDay(m_year, m_month);
			}
			else
			{
				m_day -= days;
				days = 0;
			}
		}
		return *this;
	}

	Date& operator+=(int days)
	{
		while (days > 0)
		{
			if (days + m_day > GetMonthDay(m_year, m_month))
			{
				days -= GetMonthDay(m_year, m_month) - m_day + 1;
				m_day = 1;
				if (m_month == 12)
				{
					m_month = 1;
					m_year++;
				}
				else
				{
					m_month++;
				}
			}
			else
			{
				m_day += days;
				days = 0;
			}
		}
		return *this;
	}

	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	Date operator++(int)
	{
		Date date = *this;
		*this += 1;
		return date;
	}

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	Date operator--(int)
	{
		Date date = *this;
		*this -= 1;
		return date;
	}

	bool operator<(const Date& date) const
	{
		if (m_year < date.m_year)
		{
			return true;
		}
		else if (m_year == date.m_year)
		{
			if (m_month < date.m_month)
			{
				return true;
			}
			else if (m_month == date.m_month)
			{
				if (m_day < date.m_day)
				{
					return true;
				}
			}
		}
		return false;
	}

	bool operator>(const Date& date) const
	{
		return !(*this < date) && *this != date;
	}

	bool operator==(const Date& date) const
	{
		if (m_year == date.m_year && m_month == date.m_month && m_day == date.m_day)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const Date& date) const
	{
		return !(*this == date);
	}

	int operator-(const Date& date) const
	{
		int days = 0;
		Date temp = *this;
		if (temp < date)
		{
			while (temp != date)
			{
				temp++;
				days++;
			}
		}
		else
		{
			while (temp != date)
			{
				temp--;
				days++;
			}
		}
		return abs(days) + 1;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

void Read(int& year, int& month, int& day)
{
	int date;
	cin >> date;
	year = date / 10000;
	month = date % 10000 / 100;
	day = date % 100;
}

int main()
{
	int year, month, day;
	Read(year, month, day);
	Date d1(year, month, day);
	Read(year, month, day);
	Date d2(year, month, day);
	cout << (d1 - d2) << endl;
	return 0;
}