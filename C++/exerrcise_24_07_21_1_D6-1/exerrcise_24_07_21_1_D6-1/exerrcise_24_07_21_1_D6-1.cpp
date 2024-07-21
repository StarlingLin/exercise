#define _CRT_SECURE_NO_WARNINGS

//计算两个大数的和

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string solve(string s, string t)
	{
		int i = s.size() - 1, j = t.size() - 1;
		int carry = 0;
		string res;
		while (i >= 0 || j >= 0)
		{
			int sum = carry;
			if (i >= 0)
				sum += s[i--] - '0';
			if (j >= 0)
				sum += t[j--] - '0';
			carry = sum / 10;
			res += sum % 10 + '0';
		}
		if (carry)
			res += carry + '0';
		reverse(res.begin(), res.end());
		return res;
	}
};

int main()
{
	string s, t;
	cin >> s >> t;
	Solution solution;
	cout << solution.solve(s, t) << endl;
	return 0;
}