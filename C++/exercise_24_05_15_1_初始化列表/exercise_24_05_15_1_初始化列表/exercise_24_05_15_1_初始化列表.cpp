#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		: year(year)
		, month(month)
		, day(day)
	{}

	~Date()
	{}

	void print()
	{
		cout << year << "-" << month << "-" << day << endl;
	}

private:
	int year;
	int month;
	int day;
};

int main()
{
	Date date(2015, 5, 24);
	date.print();

	return 0;
}