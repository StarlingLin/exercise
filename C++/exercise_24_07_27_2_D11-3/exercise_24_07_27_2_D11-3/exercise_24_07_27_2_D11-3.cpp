#define _CRT_SECURE_NO_WARNINGS

//�����ַ����ĵ���˳��,���ı䵥�����ַ���˳��

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
		while (i >= 0 && str[i] == ' ')	//i�����ո��ҵ����ʵ����һ���ַ�
			i--;
		if (i < 0)
			break;
		int j = i;	//jָ�򵥴ʵ����һ���ַ�
		while (j >= 0 && str[j] != ' ')	//j�ҵ����ʵĵ�һ���ַ�
			j--;
		res += str.substr(j + 1, i - j) + ' ';
		i = j;
	}
	cout << res << endl;

	return 0;
}