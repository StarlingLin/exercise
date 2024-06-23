#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//int main()
//{
//	string str;
//	cout << "Enter a string: ";
//	getline(cin, str);
//
//	int count = 0;
//	char prev = ' ';
//	for (int i = 0; i < str.length(); i++)
//	{
//		if (str[i] == ' ' && prev != ' ')
//			count++;
//		prev = str[i];
//	}
//
//	cout << "Number of words: " << count + 1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string str("Hello World.");
//	str.reserve(111);
//	str.resize(5);
//	str.reserve(50);
//	cout << str.size() << ":" << str.capacity() << endl;
//	
//	return 0;
//}

//class Solution {
//public:
//	bool isLetter(char ch)
//	{
//		if (ch >= 'a' && ch <= 'z')
//			return true;
//		if (ch >= 'A' && ch <= 'Z')
//			return true;
//		return false;
//	}
//	string reverseOnlyLetters(string S) {
//		if (S.empty())
//			return S;
//
//		size_t begin = 0, end = S.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetter(S[begin]))
//				++begin;
//
//			while (begin < end && !isLetter(S[end]))
//				--end;
//			swap(S[begin], S[end]);
//			++begin;
//			--end;
//		}
//		return S;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	string str("ab-cd");
//	cout << solution.reverseOnlyLetters(str) << endl;
//
//	str = "a-bC-dEf-ghIj";
//	cout << solution.reverseOnlyLetters(str) << endl;
//
//	str = "Test1ng-Leet=code-Q!";
//	cout << solution.reverseOnlyLetters(str) << endl;
//
//	return 0;
//}

//class Solution {
//public:
//	int firstUniqChar(string s) {
//		// 统计每个字符出现的次数
//		int count[256] = { 0 };
//		int size = s.size();
//		for (int i = 0; i < size; ++i)
//			count[s[i]] += 1;
//
//		// 按照字符次序从前往后找只出现一次的字符
//		for (int i = 0; i < size; ++i)
//			if (1 == count[s[i]])
//				return i;
//		return -1;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	string str("leetcode");
//	cout << solution.firstUniqChar(str) << endl;
//
//	str = "loveleetcode";
//	cout << solution.firstUniqChar(str) << endl;
//
//	return 0;
//}

//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main()
//{
//	string line;
//	// 不要使用cin>>line,因为会它遇到空格就结束了
//	// while(cin>>line)
//	while (getline(cin, line))
//	{
//		size_t pos = line.rfind(' ');
//		cout << line.size() - pos - 1 << endl;
//	}
//	return 0;
//}

//class Solution {
//public:
//	bool isLetterOrNumber(char ch)
//	{
//		return (ch >= '0' && ch <= '9')
//			|| (ch >= 'a' && ch <= 'z')
//			|| (ch >= 'A' && ch <= 'Z');
//	}
//
//	bool isPalindrome(string s) {
//		// 先小写字母转换成大写，再进行判断
//		for (auto& ch : s)
//		{
//			if (ch >= 'a' && ch <= 'z')
//				ch -= 32;
//		}
//
//		int begin = 0, end = s.size() - 1;
//		while (begin < end)
//		{
//			while (begin < end && !isLetterOrNumber(s[begin]))
//				++begin;
//
//			while (begin < end && !isLetterOrNumber(s[end]))
//				--end;
//
//			if (s[begin] != s[end])
//			{
//				return false;
//			}
//			else
//			{
//
//				++begin;
//				--end;
//			}
//		}
//
//		return true;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	string str;
//	while (getline(cin, str))
//	{
//		cout << solution.isPalindrome(str) << endl;
//	}
//
//	return 0;
//}

//class Solution {
//public:
//	string addstrings(string num1, string num2)
//	{
//		// 从后往前相加，相加的结果到字符串可以使用insert头插
//		// 或者+=尾插以后再reverse过来
//		int end1 = num1.size() - 1;
//		int end2 = num2.size() - 1;
//		int value1 = 0, value2 = 0, next = 0;
//		string addret;
//		while (end1 >= 0 || end2 >= 0)
//		{
//			if (end1 >= 0)
//				value1 = num1[end1--] - '0';
//			else
//				value1 = 0;
//
//			if (end2 >= 0)
//				value2 = num2[end2--] - '0';
//			else
//				value2 = 0;
//
//			int valueret = value1 + value2 + next;
//			if (valueret > 9)
//			{
//				next = 1;
//				valueret -= 10;
//			}
//			else
//			{
//				next = 0;
//			}
//
//			//addret.insert(addret.begin(), valueret+'0');
//			addret += (valueret + '0');
//		}
//
//		if (next == 1)
//		{
//			//addret.insert(addret.begin(), '1');
//			addret += '1';
//		}
//
//		reverse(addret.begin(), addret.end());
//		return addret;
//	}
//};
//
//int main()
//{
//	Solution solution;
//	string num1, num2;
//	while (cin >> num1 >> num2)
//	{
//		cout << solution.addstrings(num1, num2) << endl;
//	}
//
//	return 0;
//}

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
	{
		String tmp(s._str);
		swap(_str, tmp._str);
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	String& operator=(String& s)
	{
		swap(_str, s._str);
		return *this;
	}

private:
	char* _str;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	String s3;
	s3 = s1;
}

int main()
{
	TestString();
	return 0;
}