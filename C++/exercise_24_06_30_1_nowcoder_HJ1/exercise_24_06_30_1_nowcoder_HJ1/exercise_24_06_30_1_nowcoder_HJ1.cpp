#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

//计算字符串最后一个单词的长度，单词以空格隔开。

int main() 
{
	string str;
	while (getline(cin, str)) 
	{
		int len = 0;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				break;
			}
			len++;
		}
		cout << len << endl;
	}
	return 0;
}