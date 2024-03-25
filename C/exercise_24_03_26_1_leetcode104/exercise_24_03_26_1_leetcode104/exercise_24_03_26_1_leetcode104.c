#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

struct TreeNode* createNode(int val)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int maxDepth(struct TreeNode* root) 
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int leftDepth = maxDepth(root->left);
		int rightDepth = maxDepth(root->right);

		if (leftDepth > rightDepth)
		{
			return leftDepth + 1;
		}
		else
		{
			return rightDepth + 1;
		}
	}
}

int main()
{
	struct TreeNode* root = createNode(3);
	root->left = createNode(9);
	root->right = createNode(20);
	root->right->left = createNode(15);
	root->right->right = createNode(7);

	printf("%d\n", maxDepth(root));

	return 0;
}