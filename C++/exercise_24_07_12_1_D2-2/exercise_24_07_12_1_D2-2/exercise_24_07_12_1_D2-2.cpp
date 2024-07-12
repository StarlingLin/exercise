#define _CRT_SECURE_NO_WARNINGS

//给定整数数组cost，其中cost[i]代表从楼梯第i个台阶向上爬所需支付的代价，下标从0开始。
//每次支付代价可以爬一个台阶或者两个台阶，求爬到楼梯顶端所需的最小代价。
//输入第一行为整数n，代表楼梯的台阶数，1<=n<=100000。
//输入第二行为n个整数，代表从楼梯第i个台阶向上爬所需支付的代价，1<=cost[i]<=10000。


//DP

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* cost = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	int* dp = new int[n];
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < n; i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}

	cout << min(dp[n - 1], dp[n - 2]) << endl;

	delete[] cost;
	delete[] dp;

	return 0;
}
