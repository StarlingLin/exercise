#define _CRT_SECURE_NO_WARNINGS

//����������������д��ĸ���ַ������ʵ�һ���ӹ����Ƿ���ȫ�����ڶ����ַ����������ַ���������������

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string str1, str2;
	cin >> str1 >> str2;
	int count1[26] = { 0 }, count2[26] = { 0 };
	for (int i = 0; i < str1.size(); i++) 
	{
		count1[str1[i] - 'A']++;
	}
	for (int i = 0; i < str2.size(); i++) 
	{
		count2[str2[i] - 'A']++;
	}
	for (int i = 0; i < 26; i++) 
	{
		if (count1[i] < count2[i]) 
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}