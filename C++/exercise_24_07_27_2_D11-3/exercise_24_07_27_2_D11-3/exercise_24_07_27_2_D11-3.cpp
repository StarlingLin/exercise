#define _CRT_SECURE_NO_WARNINGS

//倒置字符串的单词顺序,不改变单词内字符的顺序

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin, str);
	string res;
	int i = str.size() - 1;
	while (i >= 0)
	{
		while (i >= 0 && str[i] == ' ')	//i跳过空格找到单词的最后一个字符
			i--;
		if (i < 0)
			break;
		int j = i;	//j指向单词的最后一个字符
		while (j >= 0 && str[j] != ' ')	//j找到单词的第一个字符
			j--;
		res += str.substr(j + 1, i - j) + ' ';
		i = j;
	}
	cout << res << endl;

	return 0;
}