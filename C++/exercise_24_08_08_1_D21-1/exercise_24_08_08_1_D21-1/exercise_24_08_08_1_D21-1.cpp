#define _CRT_SECURE_NO_WARNINGS

//n个人偶，身高1~n。将它们排成一排，但是如果某个人偶左右两边的人偶一个比它高一个比它矮，就会爆炸。
//给出不爆炸的方案。
//输入：n (3 <= n <= 100000)
//输出任意摆法。

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