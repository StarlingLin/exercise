#define _CRT_SECURE_NO_WARNINGS

//�ַ����滻����
//��ռλ��%s�滻Ϊָ���ַ���,��������б���ַ�����������ռλ���������򽫶�����ַ���ӵ�����ַ�����ĩβ

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