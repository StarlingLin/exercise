#define _CRT_SECURE_NO_WARNINGS

//��a��y��b��o��c��u�����һ���ַ���
//ÿ����һ������������ĸ���you��2��
//ÿ����һ������������ĸ���oo��1��
//����������ѯ�ʴ���q��

#include <iostream>

using namespace std;

int main()
{
	int a, b, c, q;
	cin >> q;
	while (q--)
	{
		cin >> a >> b >> c;
		int score = 0;
		while (a > 0 && b > 0 && c > 0)
		{
			score += 2;
			a--;
			b--;
			c--;
		}
		while (b > 1)
		{
			score += 1;
			b--;
		}
		cout << score << endl;
	}
	return 0;
}