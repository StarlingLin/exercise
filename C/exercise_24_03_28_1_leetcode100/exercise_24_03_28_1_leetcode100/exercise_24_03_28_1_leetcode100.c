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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) 
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	else if (p->val != q->val)
	{
		return false;
	}
	else
	{
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

TreeNode* createNode(int val)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int main()
{
	TreeNode* p = createNode(1);
	p->left = createNode(2);
	p->right = createNode(3);

	TreeNode* q = createNode(1);
	q->left = createNode(2);
	q->right = createNode(3);

	printf("%d\n", isSameTree(p, q));
	return 0;
}