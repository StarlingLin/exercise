#define _CRT_SECURE_NO_WARNINGS

//�ַ���ÿ�β�������԰����ڵ���ͬ�ַ����������ϲ���ֱ��û�����ڵ���ͬ�ַ�Ϊֹ��������յ��ַ�����������յ��ַ���Ϊ�գ������0��

#include <iostream>
#include <string>

using namespace std;

string removeSame(string str) 
{
	bool flag = true;	//����Ƿ������ڵ���ͬ�ַ�
	while (flag)
	{
		flag = false;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == str[i + 1])
			{
				str.erase(i, 2);
				flag = true;
			}
		}
	}
	if (str.empty())
	{
		return "0";
	}
	return str;
}

int main()
{
	string str;
	cin >> str;
	cout << removeSame(str) << endl;
	return 0;
}