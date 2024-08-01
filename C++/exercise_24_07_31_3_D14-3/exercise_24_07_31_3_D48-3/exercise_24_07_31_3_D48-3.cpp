#define _CRT_SECURE_NO_WARNINGS

//给定一个长度为n的仅包含正整数的数组，每次操作可以选择删除其中一个元素ai，同时删除数组中所有值等于ai-1和ai+1的数，同时获得ai分数。求最大分数。

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int deleteAndEarn(vector<int>& nums) 
{
    if (nums.empty()) return 0;

    unordered_map<int, int> count;
    int maxNum = 0;

    // 统计每个数字的出现次数并找到最大值
    for (int num : nums) 
    {
        count[num]++;
        maxNum = max(maxNum, num);
    }

    // 初始化动态规划数组
    vector<int> dp(maxNum + 1, 0);

    // 填充动态规划数组
    for (int i = 1; i <= maxNum; ++i)
    {
        int take = count[i] * i; // 选择当前数字所能获得的分数
        if (i > 1) 
        {
            take += dp[i - 2]; // 如果选择当前数字，之前可以选择的最大分数
        }
        dp[i] = max(dp[i - 1], take); // 选择当前数字或不选择当前数字的最大分数
    }

    return dp[maxNum];
}

int main() 
{
	vector<int> nums = { 3, 4, 8 };
	cout << deleteAndEarn(nums) << endl;

	return 0;
}