#define _CRT_SECURE_NO_WARNINGS

//��һ���ַ���ɾ�����г����ڵڶ����ַ����е��ַ�

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);

	for (int i = 0; i < str2.size(); i++)
	{
		for (int j = 0; j < str1.size(); j++)
		{
			if (str1[j] == str2[i])
			{
				str1.erase(j, 1);
				j--;
			}
		}
	}

	cout << str1 << endl;

	return 0;
}