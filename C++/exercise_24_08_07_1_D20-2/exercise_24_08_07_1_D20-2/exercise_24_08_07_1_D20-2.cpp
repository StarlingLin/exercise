#define _CRT_SECURE_NO_WARNINGS

//����һ������Ϊn���������飬����ѡ��һ���ǿ����������飬ʹ������������֮�;����ܴ������͡�

#include <iostream>
#include <vector>

using namespace std;

//kadane

int maxSubArray(vector<int>& nums)
{
	int n = nums.size();
	int max0 = nums[0]; //ʵʱ���ֵ
	int max1 = nums[0];	//�������ֵ
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
