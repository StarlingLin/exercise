#define _CRT_SECURE_NO_WARNINGS

//����һ��mxn����������ÿ����Ԫ�������0��1����2
//0����յ�Ԫ��1�������ʹ��ӣ�2�����õĹ���
//ÿһ���ӣ��κ��븯�õĹ������ڣ��������ң������ʹ��Ӷ��ḯ��
//����ֱ����Ԫ����û�����ʹ���Ϊֹ�����뾭������С������
//�����ʱ�򣬲����ܸ����������ʹ��ӣ�����-1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
	int rotApple(vector<vector<int>>& grid)
	{
		int m = grid.size();
		int n = grid[0].size();
		int fresh = 0;	//���ʹ��ӵ�����
		queue<pair<int, int>> q;	//���ù��ӵ�����
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 2)
				{
					q.push({ i, j });
				}
				else if (grid[i][j] == 1)
				{
					fresh++;
				}
			}
		}
		if (fresh == 0)
		{
			return 0;
		}
		int res = 0;	//���ù��ӵķ�����
		vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };	//�ĸ�����
		while (!q.empty())
		{
			res++;
			int size = q.size();
			for (int i = 0; i < size; i++)
			{
				auto cur = q.front();
				q.pop();
				for (auto dir : dirs)
				{
					int x = cur.first + dir[0];
					int y = cur.second + dir[1];
					if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
					{
						continue;
					}
					grid[x][y] = 2;
					q.push({ x, y });
					fresh--;
				}
			}
		}
		return fresh == 0 ? res - 1 : -1;
	}
};