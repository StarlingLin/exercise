#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Solution 
{
public:
    int sumOfTheDigitsOfHarshadNumber(int x) 
	{
		if (isHarshad(x))
		{
			int sum = 0;
			while (x > 0)
			{
				sum += x % 10;
				x /= 10;
			}
			return sum;
		}
		else
		{
			return -1;
		}
    }

	bool isHarshad(int num)
	{
		int sum = 0;
		int temp = num;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		return num % sum == 0;
	}
};

int main()
{
	Solution solution;
	int x;
	cout << "Enter a number: ";
	cin >> x;
	cout << "The sum of the digits of the Harshad number is " << solution.sumOfTheDigitsOfHarshadNumber(x) << endl;

	return 0;
}