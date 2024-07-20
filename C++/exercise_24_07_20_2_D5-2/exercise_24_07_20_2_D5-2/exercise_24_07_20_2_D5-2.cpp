#define _CRT_SECURE_NO_WARNINGS

//给定一个mxn的网格，其中每个单元格可能是0、1或者2
//0代表空单元格，1代表新鲜果子，2代表腐烂的果子
//每一分钟，任何与腐烂的果子相邻（上下左右）的新鲜果子都会腐烂
//返回直到单元格中没有新鲜果子为止所必须经过的最小分钟数
//如果这时候，不可能腐烂所有新鲜果子，返回-1

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
		int fresh = 0;	//新鲜果子的数量
		queue<pair<int, int>> q;	//腐烂果子的坐标
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
		int res = 0;	//腐烂果子的分钟数
		vector<vector<int>> dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };	//四个方向
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