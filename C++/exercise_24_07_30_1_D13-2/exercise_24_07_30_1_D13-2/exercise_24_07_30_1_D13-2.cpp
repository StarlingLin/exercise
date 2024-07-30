#define _CRT_SECURE_NO_WARNINGS

//给定长度为n整数的数组arr，返回arr中最长无重复连续元素子数组的长度

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int maxLength(vector<int>& arr)
	{
		int n = arr.size();
		if (n == 0)
		{
			return 0;
		}
		int res = 1;	// 最长无重复连续元素子数组的长度
		int left = 0;	// 左边界
		vector<int> last(100001, -1);	// 用于记录每个元素上一次出现的位置
		last[arr[0]] = 0;	// arr[0]的下标为0
		for (int i = 1; i < n; i++)
		{
			if (last[arr[i]] >= left)
			{
				left = last[arr[i]] + 1;
			}
			last[arr[i]] = i;
			res = max(res, i - left + 1);
		}
		return res;
	}
};