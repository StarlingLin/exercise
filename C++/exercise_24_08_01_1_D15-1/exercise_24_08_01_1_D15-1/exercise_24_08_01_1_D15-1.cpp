#define _CRT_SECURE_NO_WARNINGS

//����x�����������ȫƽ����

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