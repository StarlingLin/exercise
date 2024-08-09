#define _CRT_SECURE_NO_WARNINGS

//����һ�ýڵ���Ϊn�Ķ��������жϸö������Ƿ�Ϊƽ�������
//ƽ������������������ĸ߶Ȳ����1��������������ƽ�������������Ҳ��ƽ���������

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};

class Solution
{
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return 0;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		return max(left, right) + 1;
	}

	bool IsBalanced_Solution(TreeNode* pRoot)
	{
		if (pRoot == nullptr)
			return true;
		int left = TreeDepth(pRoot->left);
		int right = TreeDepth(pRoot->right);
		if (abs(left - right) > 1)
			return false;
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
};