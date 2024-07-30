#define _CRT_SECURE_NO_WARNINGS

//��������Ϊn����������arr������arr������ظ�����Ԫ��������ĳ���

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
		int res = 1;	// ����ظ�����Ԫ��������ĳ���
		int left = 0;	// ��߽�
		vector<int> last(100001, -1);	// ���ڼ�¼ÿ��Ԫ����һ�γ��ֵ�λ��
		last[arr[0]] = 0;	// arr[0]���±�Ϊ0
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