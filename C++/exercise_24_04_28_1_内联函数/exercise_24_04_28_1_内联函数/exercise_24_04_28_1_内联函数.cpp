#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	cout << "max(10, 20) = " << max(10, 20) << endl;
	cout << "max(0, 0) = " << max(0, 0) << endl;
	cout << "max(-10, -20) = " << max(-10, -20) << endl;

	return 0;
}

//µÈÐ§ÓÚ

//int main()
//{
//	cout << "max(10, 20) = " << (10 > 20 ? 10 : 20) << endl;
//	cout << "max(0, 0) = " << (0 > 0 ? 0 : 0) << endl;
//	cout << "max(-10, -20) = " << (-10 > -20 ? -10 : -20) << endl;
//
//	return 0;
//}