#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	int getLongestPalindrome(string A)
	{
		int n = A.size();
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			int l = i, r = i;
			while (l >= 0 && r < n && A[l] == A[r])
			{
				l--;
				r++;
			}
			if (r - l - 1 > max)
			{
				max = r - l - 1;
			}
		}
		for (int i = 0; i < n; i++)
		{
			int l = i, r = i + 1;
			while (l >= 0 && r < n && A[l] == A[r])
			{
				l--;
				r++;
			}
			if (r - l - 1 > max)
			{
				max = r - l - 1;
			}
		}
		return max;
	}
};

int main()
{
	string A = "abc1234321ab";
	Solution solution;
	cout << solution.getLongestPalindrome(A) << endl;
	return 0;
}