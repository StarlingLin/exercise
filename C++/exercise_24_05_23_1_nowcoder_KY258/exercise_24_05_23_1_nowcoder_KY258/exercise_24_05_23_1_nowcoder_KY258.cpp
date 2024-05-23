#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int y, int m, int d) : m_y(y), m_m(m), m_d(d) {}
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
	Date operator+=(int days)
	{
		while (days > 0)
		{
			if (days + m_d > GetMonthDay(m_m))
			{
				days -= GetMonthDay(m_m) - m_d + 1;
				m_d = 1;
				if (m_m == 12)
				{
					m_m = 1;
					m_y++;
				}
				else
				{
					m_m++;
				}
			}
			else
			{
				m_d += days;
				days = 0;
			}
		}
		return *this;
	}
	void Print()
	{
		printf("%04d-%02d-%02d\n", m_y, m_m, m_d);
	}

private:
	int m_y;
	int m_m;
	int m_d;
};

int main()
{
	int m = 0;
	cin >> m;
	Date* dates = (Date*)malloc(m * sizeof(Date));
	for (int i = 0; i < m; i++)
	{
		int year = 0, month = 0, day = 0, n = 0;
		cin >> year >> month >> day >> n;
		Date date(year, month, day);
		date += n;
		dates[i] = date;
	}
	for (int i = 0; i < m; i++)
	{
		dates[i].Print();
	}

	return 0;
}