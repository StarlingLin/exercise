#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1;
	cout << str1.capacity() << endl;

	string str2 = "Hello, World!";
	cout << str2.capacity() << endl;

	string str3 = "123456789012345";
	cout << str3.capacity() << endl;

	string str4 = "1234567890123456";
	cout << str4.capacity() << endl;

	return 0;
}