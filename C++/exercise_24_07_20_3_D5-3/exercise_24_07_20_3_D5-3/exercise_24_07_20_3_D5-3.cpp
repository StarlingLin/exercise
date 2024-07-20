#define _CRT_SECURE_NO_WARNINGS

//n个人围成一圈，编号0~n-1，从编号为0的人开始报数，报到m-1的人出列，剩下的人继续从0开始报数，直到剩下一个人为止，求最后剩下的人的编号。

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