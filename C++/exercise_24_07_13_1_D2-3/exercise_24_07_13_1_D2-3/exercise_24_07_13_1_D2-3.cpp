#define _CRT_SECURE_NO_WARNINGS

//�����ַ���str1��str2���������ַ�����strs������strs��str1��str2����С���룬���str1��str2Ϊnull������strs�У�����-1��
//���룺��һ������һ������n����ʾ�ַ�����strs�ĳ��ȡ��ڶ����������ַ�������ʾstr1��str2��������n�У�ÿ��һ���ַ�������ʾstrs[i]��
//��������һ����������ʾ��С���롣

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}

	int minDistance = INT_MAX;
	int lastStr1 = -1;
	int lastStr2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (strs[i] == str1)
		{
			lastStr1 = i;
			if (lastStr2 != -1)
			{
				minDistance = min(minDistance, lastStr1 - lastStr2);
			}
		}
		else if (strs[i] == str2)
		{
			lastStr2 = i;
			if (lastStr1 != -1)
			{
				minDistance = min(minDistance, lastStr2 - lastStr1);
			}
		}
	}

	if (minDistance == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << minDistance << endl;
	}

	return 0;
}
