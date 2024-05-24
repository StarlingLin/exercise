#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int year, int month, int day)
{
	m_year = year;
	m_month = month;
	m_day = day;
}

Date::Date(const Date& date)
{
	m_year = date.m_year;
	m_month = date.m_month;
	m_day = date.m_day;
}

Date::~Date()
{
}

int Date::GetMonthDays(int year, int month) const
{
	if (month == 2)
	{
		if (IsLeapYear(year))
		{
			return 29;
		}
		else
		{
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		return 30;
	}
	else
	{
		return 31;
	}
}

int Date::GetYearDays(int year) const
{
	if (IsLeapYear(year))
	{
		return 366;
	}
	else
	{
		return 365;
	}
}

bool Date::IsLeapYear(int year) const
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Date& Date::operator+(int days) const
{
	Date date = *this;
	date += days;
	return date;
}

Date& Date::operator-(int days) const
{
	Date date = *this;
	date -= days;
	return date;
}

Date& Date::operator-=(int days)
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
			m_day = GetMonthDays(m_year, m_month);
		}
		else
		{
			m_day -= days;
			days = 0;
		}
	}
	return *this;
}

Date& Date::operator+=(int days)
{
	while (days > 0)
	{
		if (days + m_day > GetMonthDays(m_year, m_month))
		{
			days -= GetMonthDays(m_year, m_month) - m_day + 1;
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

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date date = *this;
	*this += 1;
	return date;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date date = *this;
	*this -= 1;
	return date;
}

Date& Date::operator=(const Date& date)
{
	if (this != &date)
	{
		m_year = date.m_year;
		m_month = date.m_month;
		m_day = date.m_day;
	}
	return *this;
}

bool Date::operator==(const Date& date) const
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

bool Date::operator!=(const Date& date) const
{
	return !(*this == date);
}

bool Date::operator<(const Date& date) const
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

bool Date::operator>(const Date& date) const
{
	return !(*this < date) && *this != date;
}

bool Date::operator<=(const Date& date) const
{
	return *this < date || *this == date;
}

bool Date::operator>=(const Date& date) const
{
	return *this > date || *this == date;
}

int Date::operator-(const Date& date) const
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
	return days;
}

void Date::Print() const
{
	cout << m_year << "-" << m_month << "-" << m_day << endl;
}