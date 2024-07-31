#define _CRT_SECURE_NO_WARNINGS

//����һ������Ϊn�Ľ����������������飬ÿ�β�������ѡ��ɾ������һ��Ԫ��ai��ͬʱɾ������������ֵ����ai-1��ai+1������ͬʱ���ai����������������

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

    // ͳ��ÿ�����ֵĳ��ִ������ҵ����ֵ
    for (int num : nums) 
    {
        count[num]++;
        maxNum = max(maxNum, num);
    }

    // ��ʼ����̬�滮����
    vector<int> dp(maxNum + 1, 0);

    // ��䶯̬�滮����
    for (int i = 1; i <= maxNum; ++i)
    {
        int take = count[i] * i; // ѡ��ǰ�������ܻ�õķ���
        if (i > 1) 
        {
            take += dp[i - 2]; // ���ѡ��ǰ���֣�֮ǰ����ѡ���������
        }
        dp[i] = max(dp[i - 1], take); // ѡ��ǰ���ֻ�ѡ��ǰ���ֵ�������
    }

    return dp[maxNum];
}

int main() 
{
	vector<int> nums = { 3, 4, 8 };
	cout << deleteAndEarn(nums) << endl;

	return 0;
}