#define _CRT_SECURE_NO_WARNINGS

//��3*n��ѡ�ַ�Ϊn�����飬ÿ������ķ���Ϊ�ö�ѡ�ַ�������λ����ʹ�����ж���ķ���֮�����
//���룺��һ��Ϊһ������n(1<=n<=100000)����ʾ����ĸ���
//�ڶ��а���3*n������a1,a2,...,a3*n(1<=ai<=10^9)����ʾÿ��ѡ�ֵķ���

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	int n;
	cin >> n;
	vector<int> a(3 * n);
	for (int i = 0; i < 3 * n; i++) 
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long long sum = 0;
	for (int i = n; i <= 3 * n - 2; i += 2)
	{
		sum += a[i];
	}
	cout << sum << endl;
	return 0;
}