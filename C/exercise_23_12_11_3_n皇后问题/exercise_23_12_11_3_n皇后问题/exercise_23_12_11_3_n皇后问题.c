#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp08 - Basic02，GJBook3例 - 12 - 02
//
//题目名称：N皇后问题
//
//题目描述：
//
//八皇后问题由高斯(C.F.Gauss)最早在1850年提出并研究，但并未完全解决。N皇后问题指在一个N×N的棋盘上放置N个皇后，使任意两个皇后都不能互相攻击。按国际象棋规则，两个皇后，若在同一行上，或在同一列上, 或在同一条斜线上, 则她们可以互相攻击。下图即满足八皇后条件的一种棋局。
//
//编写程序给出满足条件的棋局数目。
//
//https://p.ananas.chaoxing.com/star3/origin/7526b606547480a9447d2c9b30011191.jpg
//
//输入：一个正整数N（0 < N≤13）输出：棋局数目

#include <stdio.h>
#include <stdbool.h>

#define N 20

int board[N] = { 0 };
_Bool col[N] = { false }, maindiag[2 * N] = { false }, subdiag[2 * N] = {false};
int n = 0, tot = 0;

void dfs(int i)//深度搜索
{
	if (i >= n)//该分支结束条件
	{
		tot++;
		return;
	}
	for (int j = 0; j < n; j++)
	{
		if (col[j] || maindiag[i - j + n] || subdiag[i + j])//剪枝
			continue;
		board[i] = j;//行标i棋子位于列标j
		col[j] = maindiag[i - j + n] = subdiag[i + j] = true;//占领对应列与主副对角线
		dfs(i + 1);
		col[j] = maindiag[i - j + n] = subdiag[i + j] = false;//回溯依次解除占领对应列与主副对角线
	}
}

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("%d", tot);
	return 0;
}