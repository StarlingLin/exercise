#define _CRT_SECURE_NO_WARNINGS

//����������������ֱ�Ϊnums1��nums2���ҵ����ǵĹ���Ԫ�أ����ظ�������������Щ����Ԫ����ɵ����顣

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++)
		{
			for (int j = 0; j < nums2.size(); j++)
			{
				if (nums1[i] == nums2[j])
				{
					res.push_back(nums1[i]);
					break;
				}
			}
		}

		for (int i = 0; i < res.size(); i++)
		{
			for (int j = i + 1; j < res.size(); j++)
			{
				if (res[i] == res[j])
				{
					res.erase(res.begin() + j);
					j--;
				}
			}
		}

		return res;
	}
};

int main()
{
	vector<int> nums1 = { 1, 2, 3 };
	vector<int> nums2 = { 8, 2, 2, 3, 8 };
	Solution s;
	vector<int> res = s.intersection(nums1, nums2);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}