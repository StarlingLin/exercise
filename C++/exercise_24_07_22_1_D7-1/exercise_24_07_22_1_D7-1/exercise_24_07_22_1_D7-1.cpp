#define _CRT_SECURE_NO_WARNINGS

//输出字符串的最长数字子串

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int max = 0;
	int count = 0;
	int start = 0;
	int end = 0;
	int start_max = 0;
	int end_max = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			count++;
			end = i;
		}
		else
		{
			if (count > max)
			{
				max = count;
				start_max = start;
				end_max = end;
			}
			count = 0;
			start = i + 1;
		}
	}
	if (count > max)
	{
		max = count;
		start_max = start;
		end_max = end;
	}
	for (int i = start_max; i <= end_max; i++)
	{
		cout << s[i];
	}
	cout << endl;
	
	return 0;
}