#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	while (cin >> s) 
	{
		for (int i = s.length() - 3; i > 0; i -= 3)
		{
			s.insert(i, ",");
		}
		cout << s << endl;
	}

	return 0;
}