#define _CRT_SECURE_NO_WARNINGS

//nxm�ľ���ÿ����Ԫ����һ��Сд��ĸ��
//�����Ͻǿ�ʼ��ÿ�ο������һ������ƶ�һ����Ԫ��ֱ���������½ǡ�
//����'l'��4�֣�����'o'��3�֣�����'v'��2�֣�����'e'��1�֡�
//������ܵõ����ٷ֡�

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
