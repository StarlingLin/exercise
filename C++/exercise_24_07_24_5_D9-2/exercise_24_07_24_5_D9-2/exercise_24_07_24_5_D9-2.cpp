#define _CRT_SECURE_NO_WARNINGS

//青蛙跳台阶，一次可以跳1级或2级，求跳到第n级台阶有多少种跳法

#include <iostream>
#include <vector>

using namespace std;

int jumpFloor(int number) 
{
	if (number <= 0) 
	{
		return 0;
	}
	if (number == 1) 
	{
		return 1;
	}
	if (number == 2) 
	{
		return 2;
	}
	vector<int> dp(number + 1, 0);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= number; i++) 
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[number];
}

int main()
{
	int n;
	cin >> n;
	cout << jumpFloor(n) << endl;
	return 0;
}