#define _CRT_SECURE_NO_WARNINGS

//字符串替换函数
//将占位符%s替换为指定字符串,如果参数列表的字符串个数大于占位符个数，则将多余的字符添加到结果字符串的末尾

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	string formatString(string str, vector<char>& arg)
	{
		string res;
		int i = 0;
		int j = 0;
		while (i < str.size())
		{
			if (str[i] == '%' && str[i + 1] == 's')
			{
				res += arg[j];
				++j;
				i += 2;
			}
			else
			{
				res += str[i];
				++i;
			}
		}
		while (j < arg.size())
		{
			res += arg[j];
			++j;
		}
		return res;
	}
};