#define _CRT_SECURE_NO_WARNINGS

class Solution
{
public:
	int Sum_Solution(int n)
	{
		int sum = n;
		n > 0 && (sum += Sum_Solution(n - 1));
		return sum;
	}
};