#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
	int* p = new int;

	_CrtDumpMemoryLeaks();
	return 0;
}