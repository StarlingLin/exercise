#define _CRT_SECURE_NO_WARNINGS

//n����a[1]~a[n]������С����[l, r]��ʹ��a[l]+a[l+1]+...+a[r] >= x
//�����ڶ���𰸣����l��С������l��r
//��һ������n��1<=n<=10000000����x��1<=x<=10000��
//�ڶ�������n����a[i]��1<=a[i]<=1000��

#include <iostream>
#include <vector>

using namespace std;

int main() 
{
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}

	int l = 0, r = 0;
	int sum = 0;
	int min_len = n + 1;
	int min_l = 0;
	while (r < n) 
	{
		sum += a[r];
		while (sum >= x) 
		{
			if (r - l + 1 < min_len) 
			{
				min_len = r - l + 1;
				min_l = l;
			}
			sum -= a[l];
			l++;
		}
		r++;
	}

	cout << min_l + 1 << " " << min_l + min_len << endl;

	return 0;
}