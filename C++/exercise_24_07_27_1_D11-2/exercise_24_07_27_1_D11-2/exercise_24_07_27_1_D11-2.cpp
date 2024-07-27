#define _CRT_SECURE_NO_WARNINGS

//����������prices������Ϊn��prices[i]��ʾ��i��Ĺ�Ʊ�۸�prices[0]��ʾ��0��Ĺ�Ʊ�۸�prices[1]��ʾ��1��Ĺ�Ʊ�۸��Դ����ơ�
//����������Ʊ�ܻ�õ��������
//���Զ��������Ʊ�����Ǳ���������֮ǰ��Ĺ�Ʊ
//���ܻ�ȡ�����򷵻�0
//��������

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
	vector<vector<int>> dp(n, vector<int>(2));	//dp[i][0]��ʾ��i�첻���й�Ʊ��������棬dp[i][1]��ʾ��i����й�Ʊ���������
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