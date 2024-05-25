#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}

	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);

private:
	int m_year;
	int m_month;
	int m_day;
};

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.m_year << "-" << date.m_month << "-" << date.m_day;
	return os;
}

istream& operator>>(istream& is, Date& date)
{
	cout << "请输入年月日(使用空格分割)：>";
	is >> date.m_year >> date.m_month >> date.m_day;
	return is;
}

int main()
{
	Date date1(2024, 5, 25);
	Date date2(2024, 5, 26);
	cout << date1 << endl << date2 << endl;

	cin >> date1;
	cout << date1 << endl;

	return 0;
}