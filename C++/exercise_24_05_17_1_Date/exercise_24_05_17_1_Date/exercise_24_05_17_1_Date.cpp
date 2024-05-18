#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	Date date1(2017, 5, 24);
	Date date2(2017, 5, 24);
	Date date3(2017, 5, 25);
	Date date4(2017, 6, 24);
	Date date5(2018, 5, 24);
	Date date6(2016, 5, 24);

	std::cout << "date1: ";
	date1.Print();
	std::cout << "date2: ";
	date2.Print();
	std::cout << "date3: ";
	date3.Print();
	std::cout << "date4: ";
	date4.Print();
	std::cout << "date5: ";
	date5.Print();
	std::cout << "date6: ";
	date6.Print();

	std::cout << "date1 == date2: " << (date1 == date2) << std::endl;
	std::cout << "date1 == date3: " << (date1 == date3) << std::endl;
	std::cout << "date1 == date4: " << (date1 == date4) << std::endl;
	std::cout << "date1 == date5: " << (date1 == date5) << std::endl;
	std::cout << "date1 == date6: " << (date1 == date6) << std::endl;

	std::cout << "date1 != date2: " << (date1 != date2) << std::endl;
	std::cout << "date1 != date3: " << (date1 != date3) << std::endl;
	std::cout << "date1 != date4: " << (date1 != date4) << std::endl;
	std::cout << "date1 != date5: " << (date1 != date5) << std::endl;
	std::cout << "date1 != date6: " << (date1 != date6) << std::endl;

	std::cout << "date1 < date2: " << (date1 < date2) << std::endl;
	std::cout << "date1 < date3: " << (date1 < date3) << std::endl;
	std::cout << "date1 < date4: " << (date1 < date4) << std::endl;
	std::cout << "date1 < date5: " << (date1 < date5) << std::endl;
	std::cout << "date1 < date6: " << (date1 < date6) << std::endl;

	std::cout << "date1 > date2: " << (date1 > date2) << std::endl;
	std::cout << "date1 > date3: " << (date1 > date3) << std::endl;
	std::cout << "date1 > date4: " << (date1 > date4) << std::endl;
	std::cout << "date1 > date5: " << (date1 > date5) << std::endl;
	std::cout << "date1 > date6: " << (date1 > date6) << std::endl;

	std::cout << "date1 <= date2: " << (date1 <= date2) << std::endl;
	std::cout << "date1 <= date3: " << (date1 <= date3) << std::endl;
	std::cout << "date1 <= date4: " << (date1 <= date4) << std::endl;
	std::cout << "date1 <= date5: " << (date1 <= date5) << std::endl;
	std::cout << "date1 <= date6: " << (date1 <= date6) << std::endl;

	std::cout << "date1 >= date2: " << (date1 >= date2) << std::endl;
	std::cout << "date1 >= date3: " << (date1 >= date3) << std::endl;
	std::cout << "date1 >= date4: " << (date1 >= date4) << std::endl;
	std::cout << "date1 >= date5: " << (date1 >= date5) << std::endl;
	std::cout << "date1 >= date6: " << (date1 >= date6) << std::endl;

	std::cout << "date1 - date2: " << (date1 - date2) << std::endl;
	std::cout << "date1 - date3: " << (date1 - date3) << std::endl;
	std::cout << "date1 - date4: " << (date1 - date4) << std::endl;
	std::cout << "date1 - date5: " << (date1 - date5) << std::endl;
	std::cout << "date1 - date6: " << (date1 - date6) << std::endl;

	return 0;
}