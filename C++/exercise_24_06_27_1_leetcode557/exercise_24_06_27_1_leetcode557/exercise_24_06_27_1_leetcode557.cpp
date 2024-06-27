#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	string reverseWords(string s)
	{
		string result = "";
		string word = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				for (int j = word.length() - 1; j >= 0; j--)
				{
					result += word[j];
				}
				result += ' ';
				word = "";
			}
			else
			{
				word += s[i];
			}
		}
		for (int j = word.length() - 1; j >= 0; j--)
		{
			result += word[j];
		}
		return result;
	}
};

int main()
{
	Solution solution;
	string s = "Let's take LeetCode contest";
	cout << solution.reverseWords(s) << endl;
	return 0;
}