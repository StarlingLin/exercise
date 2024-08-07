#define _CRT_SECURE_NO_WARNINGS

//给字符串，求最长非回文子字符串的长度
//1 <= |s| <= 10^7

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
	int len = s.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (s[i] != s[len - i - 1])
		{
			return false;
		}
	}
	return true;
}
bool isSame(string s)
{
	int len = s.size();
	for (int i = 0; i < len - 1; i++)
	{
		if (s[i] != s[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	int len = s.size();
	if (isSame(s))
	{
		cout << 1 << endl;
		return 0;
	}
	if (isPalindrome(s))
	{
		cout << len - 1 << endl;
		return 0;
	}
	cout << len << endl;

	return 0;
}