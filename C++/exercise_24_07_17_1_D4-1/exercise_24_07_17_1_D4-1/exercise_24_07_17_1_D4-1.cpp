#define _CRT_SECURE_NO_WARNINGS

//��������n����������Ҫִ�ж��ٴμ�1���1������ʹn��Ϊ쳲�������

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