#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Solution 
{
public:
	string reverseStr(string s, int k)
	{
		int n = s.size();
		for (int i = 0; i < n; i += 2 * k)
		{
			int left = i;
			int right = min(i + k - 1, n - 1);
			while (left < right)
			{
				swap(s[left++], s[right--]);
			}
		}
		return s;
	}
};

int main()
{
	Solution solution;
	string s = "abcdefg";
	int k = 2;
	cout << solution.reverseStr(s, k) << endl;
	return 0;
}