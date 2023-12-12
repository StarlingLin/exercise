#define _CRT_SECURE_NO_WARNINGS 1

//题目编号：Exp08 - Basic03
//
//题目名称：八皇后本质不同的解
//
//题目描述：
//
//如上题所述，当N = 8时，一共有92种可能。如果去除其中上下对称、左右对称棋局、主副
//对角线对称棋局和旋转后重复棋局，则有12种完全不同的棋局。编写程序，输出这12种棋局。
//
//输入：
//
//无
//
//输出：
//
//共12行，每行输出1种棋局，
//
//例如，第一行输出 No1 : 1 5 8 6 3 7 2 4（冒号为西文冒号且前后无多余字符，冒号后
//的每个数字后均有一个西文空格），其中No1 表示这是第1种棋局；后续数字序列表示八皇后
//所在位置，数值本身表示某个皇后在棋盘上的行坐标，该数值所在位置表示该皇后的列坐标（
// > 0)，例如，数字5位于序列的第2位，表示棋盘上第5行第2列有一个皇后；数字4位于序列
// 的第8位，表示棋盘上第4行第8列有一个皇后，由此，这8个数字描述了一种棋局。12种棋局
//的输出顺序：字典序。

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 100

int board[N] = { 0 }, solution[114514][N] = { 0 }, n = 0, tot = 0;
_Bool col[N] = { false }, maindiag[2 * N] = { false }, subdiag[2 * N] = { false }, flag = true;

void answer();//处理dfs结果并输出答案
void dfs(int i);//深度搜索
void printans(int i);//输出结果
_Bool check(int* arr1, int* arr2);//两个可能解不一样则返回false
_Bool up_down(int* arr1, int* arr2);//上下对称
_Bool left_right(int* arr1, int* arr2);//左右对称
_Bool turn_maindiag(int* arr1, int* arr2);//主对角线对称
_Bool turn_subdiag(int* arr1, int* arr2);//副对角线对称
_Bool turn_cw(int* arr1, int* arr2);//顺时针旋转对称
_Bool turn_ccw(int* arr1, int* arr2);//逆时针旋转对称
_Bool turn_central(int* arr1, int* arr2);//中心对称

int main()
{
	scanf("%d", &n);
	dfs(0);
	printf("%d\n", tot);
	answer();
	return 0;
}

void answer()
{
	for (int i = 0; i < tot; i++)
	{
		flag = true;
		for (int j = 0; j < i; j++)
			if (check(solution[i], solution[j]))
				flag = false;
		if (flag)
			printans(i);
	}
}

void printans(int i)//输出结果
{
	static int ans = 0;
	printf("No%d:", ++ans);
	for (int j = 0; j < n; j++)
		printf("%d ", solution[i][j] + 1);
	printf("\n");
}

_Bool check(int* arr1, int* arr2)//两个可能解不一样则返回false
{
	if (up_down(arr1, arr2) || left_right(arr1, arr2) || turn_maindiag(arr1, arr2) || turn_subdiag(arr1, arr2) || turn_cw(arr1, arr2) || turn_ccw(arr1, arr2) || turn_central(arr1, arr2))
		return true;
	return false;
}

_Bool up_down(int* arr1, int* arr2)//上下对称
{
	for (int i = 0; i < n; i++)
		if (arr1[i] != arr2[n - i - 1])
			return false;
	return true;
}

_Bool left_right(int* arr1, int* arr2)//左右对称
{
	for (int i = 0; i < n; i++)
		if (arr1[i] != n - arr2[i] - 1)
			return false;
	return true;
}

_Bool turn_maindiag(int* arr1, int* arr2)//主对角线对称
{
	for (int i = 0; i < n; i++)
		if (arr2[arr1[i]] != i)
			return false;
	return true;
}

_Bool turn_subdiag(int* arr1, int* arr2)//副对角线对称
{
	for (int i = 0; i < n; i++)
		if (arr2[n - arr1[i] - 1] != n - i - 1)
			return false;
	return true;
}

_Bool turn_cw(int* arr1, int* arr2)//顺时针旋转对称
{
	for (int i = 0; i < n; i++)
		if (arr2[arr1[i]] != n - 1 - i)
			return false;
	return true;
}

_Bool turn_ccw(int* arr1, int* arr2)//逆时针旋转对称
{
	for (int i = 0; i < n; i++)
		if (arr2[n - 1 - arr1[i]] != i)
			return false;
	return true;
}

_Bool turn_central(int* arr1, int* arr2)//中心对称
{
	for (int i = 0; i < n; i++)
		if (arr2[n - 1 - i] != n - 1 - arr1[i])
			return false;
	return true;
}

void dfs(int i)//深度搜索
{
	if (i >= n)//该分支结束条件
	{
		memcpy(solution[tot], board, n * sizeof(int));
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