#define _CRT_SECURE_NOWARNINGS

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello, World!";
	for (auto& c : str)
	{
		cout << c << endl;
	}

	return 0;
}