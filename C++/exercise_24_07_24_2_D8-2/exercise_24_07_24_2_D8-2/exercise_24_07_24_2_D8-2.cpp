#define _CRT_SECURE_NO_WARNINGS

//���������е���������У�ֵ�������±겻��Ҫ������

#include <iostream>
#include <vector>

using namespace std;

//wrong, ������Ŀ��
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

class Solution
{
public:
	int MLS(vector<int>& arr)
	{
		int ans = 0;
		int lenmax = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			int len = 1;
			int j = arr[i];
			while (find(arr.begin(), arr.end(), j + 1) != arr.end())
			{
				len++;
				j++;
			}
			if (len > lenmax)
			{
				lenmax = len;
				ans = lenmax;
			}
		}
		return ans;
	}
};