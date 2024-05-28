#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	//explicit Date(int y) : year(y) {}	//err
	Date(int y) : year(y), month(1), day(1) {}	//ok
	//explicit Date(int y, int m, int d) : year(y), month(m), day(d) {}	//err

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			year = d.year;
			month = d.month;
			day = d.day;
		}
		return *this;
	}

	void print() const
	{
		cout << year << "-" << month << "-" << day << endl;
	}

private:
	int day, month, year;
};

int main()
{
	Date d(2024);
	d = 2025;
	d.print();

	//隐式类型转换，但是编译器遇到连续的构造+拷贝构造会直接优化为直接构造
	const Date& dd = 2026;
	dd.print();

	return 0;
}