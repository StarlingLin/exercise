#define _CRT_SECURE_NO_WARNINGS

//给定字符串str1和str2，并给定字符数组strs，返回strs中str1和str2的最小距离，如果str1或str2为null，或不在strs中，返回-1。
//输入：第一行输入一个整数n，表示字符数组strs的长度。第二行有两个字符串，表示str1和str2。接下来n行，每行一个字符串，表示strs[i]。
//输出：输出一个整数，表示最小距离。

#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vector<string> strs(n);
	for (int i = 0; i < n; i++)
	{
		cin >> strs[i];
	}

	int minDistance = INT_MAX;
	int lastStr1 = -1;
	int lastStr2 = -1;
	for (int i = 0; i < n; i++)
	{
		if (strs[i] == str1)
		{
			lastStr1 = i;
			if (lastStr2 != -1)
			{
				minDistance = min(minDistance, lastStr1 - lastStr2);
			}
		}
		else if (strs[i] == str2)
		{
			lastStr2 = i;
			if (lastStr1 != -1)
			{
				minDistance = min(minDistance, lastStr2 - lastStr1);
			}
		}
	}

	if (minDistance == INT_MAX)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << minDistance << endl;
	}

	return 0;
}
