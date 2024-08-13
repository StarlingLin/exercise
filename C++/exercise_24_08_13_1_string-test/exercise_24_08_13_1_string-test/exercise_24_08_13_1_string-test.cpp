#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s1 = "Hello world!";
	string s2(s1);
	string s3(s1, 5, 5);
	string s4("Hello world!");
	string s5("Hello world!", 5);
	string s6(10, 'x');

	cout << "s1: " << s1 << endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
	cout << "s5: " << s5 << endl;
	cout << "s6: " << s6 << endl;

	return 0;
}