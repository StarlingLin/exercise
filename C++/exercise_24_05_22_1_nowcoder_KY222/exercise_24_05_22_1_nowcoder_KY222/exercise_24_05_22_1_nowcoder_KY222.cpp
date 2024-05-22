#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int y, int days) : m_y(y), m_m(1), m_d(1)
	{
		while(days - GetMonthDay(m_m) > 0)
		{
			days -= GetMonthDay(m_m);
			m_m++;
		}
		m_d = days;
	}
	bool IsLeapYear()
	{
		if (m_y % 4 == 0 && m_y % 100 != 0 || m_y % 400 == 0)
		{
			return true;
		}
		return false;
	}
	int GetMonthDay(int m)
	{
		if (m == 2)
		{
			if (IsLeapYear())
			{
				return 29;
			}
			return 28;
		}
		if (m == 4 || m == 6 || m == 9 || m == 11)
		{
			return 30;
		}
		return 31;
	}
	void Print()
	{
		printf("%d-%02d-%02d\n", m_y, m_m, m_d);
	}

private:
	int m_y;
	int m_m;
	int m_d;
};

int main()
{
	int y = 1, days = 1;
	while (cin >> y >> days)
	{
		Date(y, days).Print();
	}

	return 0;
}