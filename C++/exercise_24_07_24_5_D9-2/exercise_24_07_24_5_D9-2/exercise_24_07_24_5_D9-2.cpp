#define _CRT_SECURE_NO_WARNINGS

//������̨�ף�һ�ο�����1����2������������n��̨���ж���������

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