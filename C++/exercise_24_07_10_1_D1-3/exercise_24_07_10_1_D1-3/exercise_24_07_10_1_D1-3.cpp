#define _CRT_SECURE_NO_WARNINGS

//�ַ���ÿ�β�������԰����ڵ���ͬ�ַ����������ϲ���ֱ��û�����ڵ���ͬ�ַ�Ϊֹ��������յ��ַ�����������յ��ַ���Ϊ�գ������0��

#include <iostream>
#include <string>

using namespace std;

//ʱ�临�Ӷȹ��ߣ�����
//string removeSame(string str) 
//{
//	bool flag = true;	//����Ƿ������ڵ���ͬ�ַ�
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

//ʱ�临�Ӷ�ΪO(n)
string removeSame(string str)
{
	string res;
	for (int i = 0; i < str.size(); i++)
	{
		if (res.empty() || res.back() != str[i])	//ջΪ�ջ���ջ��Ԫ���뵱ǰԪ�ز����
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