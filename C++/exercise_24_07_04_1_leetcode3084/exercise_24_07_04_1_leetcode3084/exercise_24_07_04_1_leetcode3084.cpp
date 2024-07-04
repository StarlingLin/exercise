#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <ranges>

// ����һ���ַ��� s ��һ���ַ� c ���������ַ��� s �в����� c �ַ���ͷ�ͽ�β�ķǿ����ַ�����������

using namespace std;

//class Solution
//{
//public:
//	long long countSubstrings(string s, char c)
//	{
//        int count = 0;
//        int n = s.length();
//
//        for (int i = 0; i < n; ++i) 
//        {
//            if (s[i] == c) 
//            {
//                for (int j = i + 1; j <= n; ++j) 
//                {
//                    if (s[j - 1] == c) 
//                    {
//                        ++count;
//                    }
//                }
//            }
//        }
//
//        return count;
//	}
//};


class Solution
{
public:
	long long countSubstrings(string s, char c)
	{
		long long ans = 0;
		for (auto& x : s)
			if (x == c)
				ans++;
		return (ans + 1) * ans / 2;
	}
};

int main()
{
	Solution solution;
	cout << solution.countSubstrings("ababa", 'a') << endl;
}