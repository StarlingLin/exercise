#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s("Hello world!");
	cout << s.capacity() << endl;
	s.reserve(5);
	cout << s.capacity() << endl;
	s.reserve(111);
	cout << s.capacity() << endl;
	s.reserve(112);
	cout << s.capacity() << endl;

	return 0;
}