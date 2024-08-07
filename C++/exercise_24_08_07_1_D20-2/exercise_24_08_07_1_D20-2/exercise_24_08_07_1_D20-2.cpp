#define _CRT_SECURE_NO_WARNINGS

//给定一个长度为n的整数数组，从中选出一个非空连续子数组，使该数组所有数之和尽可能大，求最大和。

#include <iostream>
#include <vector>

using namespace std;

//kadane

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	int max0 = nums[0]; //实时最大值
	int max1 = nums[0];	//迄今最大值
	for (int i = 1; i < n; i++)
	{
		max0 = max(max0 + nums[i], nums[i]);
		max1 = max(max0, max1);
	}
	return max1;
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	cout << maxSubArray(nums) << endl;
	
	return 0;
}
