#define _CRT_SECURE_NO_WARNINGS

//�ֶ�n���ˣ���Ϊm�飬ÿ�����ó�һ��������ÿ����������ó�ͬһ����������ͬ������ó�ͬһ����������֤�������������������
//���룺��һ������n m��������һ������n��������ʾÿ�����ó��������������������������������޷��������-1

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N], g[N], cnt[N];	//a��ÿ�����ó���������g��ÿ��������������cnt��ÿ�������

int n, m, k;

bool check(int x)
{
	int group = 0;
	for (int i = 0; i < k; i++)
	{
		group += cnt[i] / x + bool(cnt[i] % x);//��ȡ��
	}

	if (group <= m) return true;//Ҫ������ == m �ģ�<=��>=���ɣ��� l��r ��ȡֵ���
	else return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		g[a[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (g[i]) cnt[k++] = g[i];//���µ�����ȥ��ÿһ������
	}

	if (k > m)//�ֵ���������е��������޷�����
	{
		puts("-1");
		return 0;
	}

	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = l + r >> 1;// mid Ϊ ÿ�����������ֵ
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r << endl;

	return 0;
}