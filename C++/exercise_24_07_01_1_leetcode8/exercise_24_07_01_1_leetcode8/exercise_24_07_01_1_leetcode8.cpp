#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	int myAtoi(string s)
	{
		int i = 0;
		int sign = 1;
		int result = 0;

		while (s[i] == ' ')
		{
			i++;
		}

		if (s[i] == '-')
		{
			sign = -1;
			i++;
		}
		else if (s[i] == '+')
		{
			i++;
		}

		while (s[i] >= '0' && s[i] <= '9')
		{
			if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > 7))
			{
				if (sign == 1)
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
			}

			result = result * 10 + (s[i] - '0');
			i++;
		}

		return result * sign;
	}
};

int main()
{
	Solution solution;

	string s = "42";
	cout << solution.myAtoi(s) << endl;

	s = "   -42";
	cout << solution.myAtoi(s) << endl;

	s = "4193 with words";
	cout << solution.myAtoi(s) << endl;

	s = "words and 987";
	cout << solution.myAtoi(s) << endl;

	s = "-91283472332";
	cout << solution.myAtoi(s) << endl;

	s = "3.14159";
	cout << solution.myAtoi(s) << endl;

	s = " ";
	cout << solution.myAtoi(s) << endl;

	s = "  -0012a42";
	cout << solution.myAtoi(s) << endl;

	s = "21474836460";
	cout << solution.myAtoi(s) << endl;

	s = "2147483648";
	cout << solution.myAtoi(s) << endl;

	return 0;
}	