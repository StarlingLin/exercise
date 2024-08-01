#define _CRT_SECURE_NO_WARNINGS

//乐队n个人，分为m组，每个人擅长一个声部，每组的所有人擅长同一个声部，不同组可以擅长同一个声部，保证人数最多的组的人数最少
//输入：第一行输入n m，接下来一行输入n个数，表示每个人擅长的声部，输出：人数最多的组的人数，无法分组输出-1

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int a[N], g[N], cnt[N];	//a存每个人擅长的声部，g存每个声部的人数，cnt存每组的人数

int n, m, k;

bool check(int x)
{
	int group = 0;
	for (int i = 0; i < k; i++)
	{
		group += cnt[i] / x + bool(cnt[i] % x);//上取整
	}

	if (group <= m) return true;//要找组数 == m 的，<=、>=都可，但 l，r 的取值会变
	else return false;
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		g[a[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (g[i]) cnt[k++] = g[i];//用新的数组去存每一组人数
	}

	if (k > m)//分的组大于已有的组数，无法分组
	{
		puts("-1");
		return 0;
	}

	int l = 0, r = n - 1;
	while (l < r)
	{
		int mid = l + r >> 1;// mid 为 每组人数的最大值
		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	cout << r << endl;

	return 0;
}