#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}

		string result = "0";
		string zero = "";
		for (int i = num2.size() - 1; i >= 0; i--)
		{
			string temp = multiply(num1, num2[i]);
			temp += zero;
			result = add(result, temp);
			zero += "0";
		}

		return result;
	}

	string multiply(string num1, char num2)
	{
		if (num2 == '0')
		{
			return "0";
		}

		string result = "";
		int carry = 0;
		for (int i = num1.size() - 1; i >= 0; i--)
		{
			int temp = (num1[i] - '0') * (num2 - '0') + carry;
			result = to_string(temp % 10) + result;
			carry = temp / 10;
		}

		if (carry > 0)
		{
			result = to_string(carry) + result;
		}

		return result;
	}

	string add(string num1, string num2)
	{
		string result = "";
		int carry = 0;
		int i = num1.size() - 1;
		int j = num2.size() - 1;
		while (i >= 0 || j >= 0)
		{
			int temp = carry;
			if (i >= 0)
			{
				temp += num1[i] - '0';
				i--;
			}
			if (j >= 0)
			{
				temp += num2[j] - '0';
				j--;
			}
			result = to_string(temp % 10) + result;
			carry = temp / 10;
		}

		if (carry > 0)
		{
			result = to_string(carry) + result;
		}

		return result;
	}
};

int main()
{
	Solution solution;
	string num1 = "123";
	string num2 = "456";
	cout << solution.multiply(num1, num2) << endl;

	num1 = "2";
	num2 = "3";
	cout << solution.multiply(num1, num2) << endl;

	num1 = "123";
	num2 = "0";
	cout << solution.multiply(num1, num2) << endl;

	num1 = "0";
	num2 = "123";
	cout << solution.multiply(num1, num2) << endl;

	num1 = "0";
	num2 = "0";
	cout << solution.multiply(num1, num2) << endl;

	num1 = "123";
	num2 = "456";
	cout << solution.add(num1, num2) << endl;

	num1 = "2";
	num2 = "3";
	cout << solution.add(num1, num2) << endl;

	num1 = "123";
	num2 = "0";
	cout << solution.add(num1, num2) << endl;

	num1 = "0";
	num2 = "123";
	cout << solution.add(num1, num2) << endl;

	num1 = "0";
	num2 = "0";
	cout << solution.add(num1, num2) << endl;

	return 0;
}