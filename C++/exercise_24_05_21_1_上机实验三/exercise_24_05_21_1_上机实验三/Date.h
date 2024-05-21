#pragma once

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	Date(const Date& date);
	~Date();

	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;

	int GetMonthDays(int year, int month) const;
	int GetYearDays(int year) const;
	bool IsLeapYear(int year) const;

	Date& operator+(int days) const;
	Date& operator-(int days) const;
	Date& operator-=(int days);
	Date& operator+=(int days);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date& operator=(const Date& date);
	bool operator==(const Date& date) const;
	bool operator!=(const Date& date) const;
	bool operator<(const Date& date) const;
	bool operator>(const Date& date) const;
	bool operator<=(const Date& date) const;
	bool operator>=(const Date& date) const;
	int operator-(const Date& date) const;

	void Print() const;

private:
	int m_year;
	int m_month;
	int m_day;
};