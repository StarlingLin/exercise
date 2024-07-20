#define _CRT_SECURE_NO_WARNINGS

//有a个y，b个o，c个u，组成一个字符串
//每存在一次相邻三个字母组成you加2分
//每存在一次相邻两个字母组成oo加1分
//求最大分数（询问次数q）

#include <iostream>

using namespace std;

int main()
{
	int a, b, c, q;
	cin >> q;
	while (q--)
	{
		cin >> a >> b >> c;
		int score = 0;
		while (a > 0 && b > 0 && c > 0)
		{
			score += 2;
			a--;
			b--;
			c--;
		}
		while (b > 1)
		{
			score += 1;
			b--;
		}
		cout << score << endl;
	}
	return 0;
}