#define _CRT_SECURE_NO_WARNINGS

//将字符串重复的字符压缩，例如字符串“aabbccdd”压缩为“a2b2c2d2”，如果只有一个字符，则不压缩，例如“abcd”不压缩。

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string compressString(const string& str)
	{
		string result;
		char lastChar = str[0];
		int count = 1;
		for (size_t i = 1; i < str.size(); i++)
		{
			if (str[i] == lastChar)
			{
				count++;
			}
			else
			{
				result += lastChar;
				if (count > 1)
				{
					result += to_string(count);
				}
				lastChar = str[i];
				count = 1;
			}
		}
		result += lastChar;
		if (count > 1)
		{
			result += to_string(count);
		}
		return result;
	}
};

int main()
{
	string str;
	cin >> str;
	Solution s;
	cout << s.compressString(str) << endl;
	return 0;
}