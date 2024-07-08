#define _CRT_SECURE_NO_WARNINGS

//统计某个给定范围[L,R]内所有整数中数字2出现的次数
//输入共一行，包含两个整数L和R，之间用一个空格隔开

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