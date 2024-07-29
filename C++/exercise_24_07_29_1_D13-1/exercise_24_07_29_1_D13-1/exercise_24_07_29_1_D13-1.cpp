#define _CRT_SECURE_NO_WARNINGS

//每场游戏失败扣一分，获胜如果触发至少三连胜加k分，没有三连胜加1分
//求最终得分
//第一行输入整数T，表示测试用例的组数
//每组测试的第一行输入整数n和k，表示游戏的场数与连胜的加分
//接下来一行输入长度为n的字符串，表示每场游戏的结果，其中W表示获胜，L表示失败

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int T;
	cin >> T;
	while (T--) 
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int score = 0;
		int win = 0;
		for (int i = 0; i < n; i++) 
		{
			if (s[i] == 'W') 
			{
				score++;
				win++;
				if (win >= 3) 
				{
					score += k - 1;
				}
			}
			else 
			{
				score--;
				win = 0;
			}
		}
		cout << score << endl;
	}
	return 0;
}