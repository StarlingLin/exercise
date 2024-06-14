#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cout << "Enter a string: ";
	getline(cin, str);

	int count = 0;
	char prev = ' ';
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == ' ' && prev != ' ')
			count++;
		prev = str[i];
	}

	cout << "Number of words: " << count + 1 << endl;

	return 0;
}