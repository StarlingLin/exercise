#define _CRT_SECURE_NO_WARNINGS

//ͳ��ĳ��������Χ[L,R]����������������2���ֵĴ���
//���빲һ�У�������������L��R��֮����һ���ո����

#include <iostream>

using namespace std;

int main() 
{
	int L, R;
	cin >> L >> R;
	int count = 0;
	for (int i = L; i <= R; i++) 
	{
		int temp = i;
		while (temp) 
		{
			if (temp % 10 == 2) 
			{
				count++;
			}
			temp /= 10;
		}
	}
	cout << count << endl;
	return 0;
}