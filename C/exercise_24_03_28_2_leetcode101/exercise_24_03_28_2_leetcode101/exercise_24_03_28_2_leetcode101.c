#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
	{
		return true;
	}
	else if (left == NULL || right == NULL)
	{
		return false;
	}
	else if (left->val != right->val)
	{
		return false;
	}
	return _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root)
{
	return _isSymmetric(root->left, root->right);
}