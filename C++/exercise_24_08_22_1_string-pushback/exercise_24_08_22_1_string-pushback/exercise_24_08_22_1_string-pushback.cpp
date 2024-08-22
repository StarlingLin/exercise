#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello";
	cout << "str: " << str << endl;

	str.push_back(' ');
	cout << "str: " << str << endl;

	str.push_back('W');
	cout << "str: " << str << endl;

	str.push_back('o');
	cout << "str: " << str << endl;

	str.push_back('r');
	cout << "str: " << str << endl;

	str.push_back('l');
	cout << "str: " << str << endl;

	str.push_back('d');
	cout << "str: " << str << endl;

	return 0;
}