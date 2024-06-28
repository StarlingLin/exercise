#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void func()
{
	int* n = new int[100000000000];
}

int main()
{
	try
	{
		func();
	}
	catch (const exception& e)
	{
		cout << "Error: " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error: Unknown error" << endl;
	}

	return 0;
}