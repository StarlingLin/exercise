#define _CRT_SECURE_NO_WARNINGS

//将3*n个选手分为n个队伍，每个队伍的分数为该队选手分数的中位数，使得所有队伍的分数之和最大
//输入：第一行为一个整数n(1<=n<=100000)，表示队伍的个数
//第二行包括3*n个整数a1,a2,...,a3*n(1<=ai<=10^9)，表示每个选手的分数

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