#define _CRT_SECURE_NO_WARNINGS

//ÿ����Ϸʧ�ܿ�һ�֣���ʤ���������������ʤ��k�֣�û������ʤ��1��
//�����յ÷�
//��һ����������T����ʾ��������������
//ÿ����Եĵ�һ����������n��k����ʾ��Ϸ�ĳ�������ʤ�ļӷ�
//������һ�����볤��Ϊn���ַ�������ʾÿ����Ϸ�Ľ��������W��ʾ��ʤ��L��ʾʧ��

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int T;
	cin >> T;
	while (T--) 
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int score = 0;
		int win = 0;
		for (int i = 0; i < n; i++) 
		{
			if (s[i] == 'W') 
			{
				score++;
				win++;
				if (win >= 3) 
				{
					score += k - 1;
				}
			}
			else 
			{
				score--;
				win = 0;
			}
		}
		cout << score << endl;
	}
	return 0;
}