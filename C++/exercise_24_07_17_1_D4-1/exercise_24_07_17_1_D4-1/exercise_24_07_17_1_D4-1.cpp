#define _CRT_SECURE_NO_WARNINGS

//给定数字n，求最少需要执行多少次加1或减1操作，使n成为斐波那契数

#include <iostream>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	int a = 0, b = 1, c = 1;
	while (c < n) 
	{
		a = b;
		b = c;
		c = a + b;
	}
	cout << (((c - n) < (n - b)) ? (c - n) : (n - b)) << endl;
	return 0;
}