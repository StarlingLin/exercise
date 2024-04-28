#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

void TestForLoop()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		arr[i] *= 2;
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << " ";
	}
}

void TestForLoopWithRange()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	for (auto& e : arr)
	{
		e *= 2;
	}
	for (auto e : arr)
	{
		cout << e << " ";
	}
}

int main()
{
	TestForLoop();
	cout << endl;
	TestForLoopWithRange();
	return 0;
}