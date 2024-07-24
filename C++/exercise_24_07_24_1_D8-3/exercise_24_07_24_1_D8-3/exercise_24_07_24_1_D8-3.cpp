#define _CRT_SECURE_NO_WARNINGS

//nxm的矩阵，每个单元格有一个小写字母。
//从左上角开始，每次可以向右或向下移动一个单元格，直到到达右下角。
//遇到'l'加4分，遇到'o'加3分，遇到'v'加2分，遇到'e'加1分。
//求最多能得到多少分。

#include <iostream>
#include <vector>

using namespace std;

#define SCORE(a, b) (matrix[a][b] == 'l' ? 4 : (matrix[a][b] == 'o' ? 3 : (matrix[a][b] == 'v' ? 2 : (matrix[a][b] == 'e' ? 1 : 0))))

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> matrix(n, vector<char>(m));
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	}
	dp[0][0] = SCORE(0, 0);
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + SCORE(i, 0);
	for (int i = 1; i < m; i++)
		dp[0][i] = dp[0][i - 1] + SCORE(0, i);
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + SCORE(i, j);
		}
	}
	cout << dp[n - 1][m - 1] << endl;
	return 0;
}
