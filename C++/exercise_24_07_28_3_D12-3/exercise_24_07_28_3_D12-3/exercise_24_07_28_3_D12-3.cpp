#define _CRT_SECURE_NO_WARNINGS

//仅由小写字母组成的字符串，求一共有多少个'shy'子序列（不要求连续）。
//第一行输入一个整数n(1<=n<=300000)，表示字符串的长度。
//第二行输入一个字符串，长度为n。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	string str;
	cin >> str;

	long long s = 0, sh = 0, shy = 0;

	for (char c : str)
	{
		if (c == 's')
		{
			s++;
		}
		else if (c == 'h')
		{
			sh += s;
		}
		else if (c == 'y')
		{
			shy += sh;
		}
	}

	cout << shy << endl;

	return 0;
}