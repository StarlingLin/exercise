#define _CRT_SECURE_NO_WARNINGS

//给出一个二维字符数组和一个单词，判断单词是否在二维字符数组中出现
//单词在数组中出现的条件是：单词中的每个字母都在数组中的相邻位置上（上下左右四个方向）。
//同一个位置的字母不能被重复使用。
//例如：
//给出二维字符数组：
//[
//	['a', 'b', 'c', 'e'],
//	['s', 'f', 'c', 's'],
//	['a', 'd', 'e', 'e']
//]
//单词： "abcced" -> true
//单词： "see" -> true
//单词： "abcb" -> false

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	bool dfs(vector<string>& board, string& word, int index, int i, int j, vector<vector<bool>>& visited)
	{
		if (index == word.size())
			return true;

		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
			return false;

		visited[i][j] = true;
		bool res = dfs(board, word, index + 1, i - 1, j, visited) ||
			dfs(board, word, index + 1, i + 1, j, visited) ||
			dfs(board, word, index + 1, i, j - 1, visited) ||
			dfs(board, word, index + 1, i, j + 1, visited);
		visited[i][j] = false;

		return res;
	}

	bool exist(vector<string>& board, string word)
	{
		if (board.empty() || board[0].empty())
			return false;

		int m = board.size();
		int n = board[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dfs(board, word, 0, i, j, visited))
					return true;
			}
		}

		return false;
	}
};