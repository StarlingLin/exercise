#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

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

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string line;
	// 不要使用cin>>line,因为会它遇到空格就结束了
	// while(cin>>line)
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}