#define _CRT_SECURE_NO_WARNINGS

//无序数组中的最长连续序列（值连续，下标不需要连续）

#include <iostream>
#include <vector>

using namespace std;

//wrong, 看错题目了
//class Solution
//{
//public:
//	int MLS(vector<int>& arr)
//	{
//		int prev, curr, ans, len, lenmax;
//		ans = prev = curr = len = lenmax = 0;
//		while (curr != arr.size() - 1)
//		{
//			if (arr[curr] + 1 == arr[curr + 1])
//			{
//				curr++;
//				len++;
//			}
//			else
//			{
//				if (len > lenmax)
//				{
//					lenmax = len;
//					ans = prev;
//				}
//				prev = curr;
//				curr++;
//				len = 0;
//			}
//		}
//		return ans;
//	}
//};

//复杂度过高O(n^2)，超时
//class Solution
//{
//public:
//	int MLS(vector<int>& arr)
//	{
//		int ans = 0;
//		int lenmax = 0;
//		for (int i = 0; i < arr.size(); i++)
//		{
//			int len = 1;
//			int j = arr[i];
//			while (find(arr.begin(), arr.end(), j + 1) != arr.end())
//			{
//				len++;
//				j++;
//			}
//			if (len > lenmax)
//			{
//				lenmax = len;
//				ans = lenmax;
//			}
//		}
//		return ans;
//	}
//};

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int MLS(vector<int>& arr)
    {
        if (arr.empty()) return 0;

        sort(arr.begin(), arr.end());

        int lenmax = 1;
        int currentStreak = 1; 

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] != arr[i - 1])
            {
                if (arr[i] == arr[i - 1] + 1) 
                {
                    currentStreak++;
                }
                else 
                {
                    lenmax = max(lenmax, currentStreak);
                    currentStreak = 1;
                }
            }
        }

        lenmax = max(lenmax, currentStreak);

        return lenmax;
    }
};
