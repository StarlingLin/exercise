#define _CRT_SECURE_NO_WARNINGS

//给出x，求最近的完全平方数

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long x;
	cin >> x;
	long long i = sqrt(x);
	cout << ((abs(i * i - x) > abs((i + 1) * (i + 1) - x)) ? (i + 1) * (i + 1) : i * i);

	return 0;
}