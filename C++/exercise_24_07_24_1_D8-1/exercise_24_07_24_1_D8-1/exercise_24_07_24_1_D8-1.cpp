#define _CRT_SECURE_NO_WARNINGS

//最小公倍数

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	long long a, b;
	cin >> a >> b;
	long long max = a > b ? a : b;
	long long min = a < b ? a : b;
	long long i = 1;
	while (true) 
	{
		if ((max * i) % min == 0) 
		{
			cout << max * i << endl;
			break;
		}
		i++;
	}
	return 0;
}