#define _CRT_SECURE_NO_WARNINGS

//n����ż�����1~n���������ų�һ�ţ��������ĳ����ż�������ߵ���żһ��������һ�����������ͻᱬը��
//��������ը�ķ�����
//���룺n (3 <= n <= 100000)
//�������ڷ���

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		v[i] = i + 1;
	}
	for (int i = 1; i < n - 1; i += 2)
	{
		swap(v[i], v[i + 1]);
	}
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}