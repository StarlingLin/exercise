#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s = "Hello";
	cout << "s = " << s << endl;
	cout << "s.size() = " << s.size() << endl;

	s.resize(4);
	cout << "s = " << s << endl;
	cout << "s.size() = " << s.size() << endl;

	s.resize(6, '!');
	cout << "s = " << s << endl;
	cout << "s.size() = " << s.size() << endl;

	s.resize(10);
	cout << "s = " << s << endl;
	cout << "s.size() = " << s.size() << endl;

	s.resize(12, '?');
	cout << "s = " << s << endl;
	cout << "s.size() = " << s.size() << endl;

	return 0;
}