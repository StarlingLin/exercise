#define _CRT_SECURE_NO_WARNINGS

//字符串每次操作后可以把相邻的相同字符消除，不断操作直到没有相邻的相同字符为止，输出最终的字符串，如果最终的字符串为空，则输出0。

#include <iostream>
#include <string>

using namespace std;

//时间复杂度过高，舍弃
//string removeSame(string str) 
//{
//	bool flag = true;	//标记是否有相邻的相同字符
//	while (flag)
//	{
//		flag = false;
//		for (int i = 0; i < str.size(); i++)
//		{
//			if (str[i] == str[i + 1])
//			{
//				str.erase(i, 2);
//				flag = true;
//			}
//		}
//	}
//	if (str.empty())
//	{
//		return "0";
//	}
//	return str;
//}

//时间复杂度为O(n)
string removeSame(string str)
{
	string res;
	for (int i = 0; i < str.size(); i++)
	{
		if (res.empty() || res.back() != str[i])	//栈为空或者栈顶元素与当前元素不相等
		{
			res.push_back(str[i]);
		}
		else
		{
			res.pop_back();
		}
	}
	if (res.empty())
	{
		return "0";
	}
	return res;
}

int main()
{
	string str;
	cin >> str;
	cout << removeSame(str) << endl;
	return 0;
}