#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

//class Solution 
//{
//public:
//    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) 
//    {
//        for (int j = 0; j < matrix[0].size(); j++) 
//        {
//            int mx = 0;
//            for (auto& row : matrix) 
//            {
//                mx = max(mx, row[j]);
//            }
//            for (auto& row : matrix) 
//            {
//                if (row[j] == -1) 
//                {
//                    row[j] = mx;
//                }
//            }
//        }
//        return matrix;
//    }
//};

class Solution 
{
public:
	vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix)
	{
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> result(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == -1)
				{
					for (int k = 0; k < cols; k++)
					{
						result[i][k] = matrix[i][k];
					}
					for (int k = 0; k < rows; k++)
					{
						result[k][j] = matrix[k][j];
					}
				}
			}
		}
		return result;
	}

};

int main() {
	Solution solution;
	vector<vector<int>> matrix = { {1, 2, -1}, {4, -1, 6}, {7, 8, 9} };
	vector<vector<int>> result = solution.modifiedMatrix(matrix);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}