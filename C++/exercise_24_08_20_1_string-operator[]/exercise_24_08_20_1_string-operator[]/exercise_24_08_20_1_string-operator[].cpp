#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}

	str[0] = 'h';
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << endl;
	}

	return 0;
}