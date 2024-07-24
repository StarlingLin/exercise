#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool IsContinuous(vector<int>& numbers)
	{
		sort(numbers.begin(), numbers.end());

		int zeroCount = 0;
		int gapCount = 0;
		for (int i = 0; i < numbers.size(); i++)
		{
			if (numbers[i] == 0)
				zeroCount++;
			else if (i < numbers.size() - 1 && numbers[i] == numbers[i + 1])	// сп╤твс
				return false;
			else if (i < numbers.size() - 1 && numbers[i] + 1 != numbers[i + 1])
				gapCount += numbers[i + 1] - numbers[i] - 1;
		}

		return zeroCount >= gapCount;
	}
};