#define _CRT_SECURE_NO_WARNINGS

//����Сд��ĸ��ɵ��ַ�������һ���ж��ٸ�'shy'�����У���Ҫ����������
//��һ������һ������n(1<=n<=300000)����ʾ�ַ����ĳ��ȡ�
//�ڶ�������һ���ַ���������Ϊn��

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	string str;
	cin >> str;

	long long s = 0, sh = 0, shy = 0;

	for (char c : str)
	{
		if (c == 's')
		{
			s++;
		}
		else if (c == 'h')
		{
			sh += s;
		}
		else if (c == 'y')
		{
			shy += sh;
		}
	}

	cout << shy << endl;

	return 0;
}