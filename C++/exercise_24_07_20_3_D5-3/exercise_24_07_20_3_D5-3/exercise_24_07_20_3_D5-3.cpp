#define _CRT_SECURE_NO_WARNINGS

//n����Χ��һȦ�����0~n-1���ӱ��Ϊ0���˿�ʼ����������m-1���˳��У�ʣ�µ��˼�����0��ʼ������ֱ��ʣ��һ����Ϊֹ�������ʣ�µ��˵ı�š�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int LastRemaining_Solution(int n, int m)
	{
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			v[i] = i;
		}
		int i = 0;
		while (n > 1)
		{
			i = (i + m - 1) % n;
			v.erase(v.begin() + i);
			n--;
		}
		return v[0];
	}
};