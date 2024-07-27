#define _CRT_SECURE_NO_WARNINGS

//假设有数组prices，长度为n，prices[i]表示第i天的股票价格，prices[0]表示第0天的股票价格，prices[1]表示第1天的股票价格，以此类推。
//返回买卖股票能获得的最大收益
//可以多次买卖股票，但是必须先卖出之前买的股票
//不能获取收益则返回0
//无手续费

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) 
{
	int n = prices.size();
	if (n == 0) 
	{
		return 0;
	}
	vector<vector<int>> dp(n, vector<int>(2));	//dp[i][0]表示第i天不持有股票的最大收益，dp[i][1]表示第i天持有股票的最大收益
	dp[0][0] = 0;
	dp[0][1] = -prices[0];
	for (int i = 1; i < n; i++) 
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
	}
	return dp[n - 1][0];
}

int main()
{
	int n;
	vector<int> prices;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		prices.push_back(temp);
	}
	cout << maxProfit(prices) << endl;

	return 0;
}