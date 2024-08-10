#define _CRT_SECURE_NO_WARNINGS

//已知矩阵的大小定义为其中所有元素的和
//给定一个N*N矩阵，找到一个子矩阵，使得子矩阵的大小最大
//第一行输入N，表示矩阵的行数和列数
//接下来输入N*N个整数，表示矩阵中的元素

//样例通过率87.5%
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	int N;
//	cin >> N;
//	vector<vector<int>> matrix(N, vector<int>(N));
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cin >> matrix[i][j];
//		}
//	}
//
//	vector<vector<int>> sum(N + 1, vector<int>(N + 1));
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++)
//		{
//			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
//		}
//	}
//
//	int max_size = 0;
//	for (int i1 = 0; i1 < N; i1++)
//	{
//		for (int j1 = 0; j1 < N; j1++)
//		{
//			for (int i2 = i1 + 1; i2 <= N; i2++)
//			{
//				for (int j2 = j1 + 1; j2 <= N; j2++)
//				{
//					int size = sum[i2][j2] - sum[i1][j2] - sum[i2][j1] + sum[i1][j1];
//					max_size = max(max_size, size);
//				}
//			}
//		}
//	}
//
//	cout << max_size << endl;
//
//	return 0;
//}

//AC
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums)	//最大子序和
{
	int max_sum = nums[0];
	int current_sum = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		current_sum = max(nums[i], current_sum + nums[i]);
		max_sum = max(max_sum, current_sum);
	}
	return max_sum;
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> matrix(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int max_sum = INT_MIN;	//最大子矩阵的大小
	for (int left = 0; left < N; left++)	//枚举左边界
	{
		vector<int> temp(N, 0);
		for (int right = left; right < N; right++)	//枚举右边界
		{
			for (int i = 0; i < N; i++)	//计算每一行的和
			{
				temp[i] += matrix[i][right];
			}
			max_sum = max(max_sum, maxSubArray(temp));	//计算每一行的和的最大子序和
		}
	}

	cout << max_sum << endl;

	return 0;
}