#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

bool isUnivalTree(struct TreeNode* root) 
{
	if (root == NULL) {
		return true;
	}
	if (root->left != NULL && root->val != root->left->val) {
		return false;
	}
	if (root->right != NULL && root->val != root->right->val) {
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

struct TreeNode* createNode(int val)
{
	struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int main()
{
	struct TreeNode* root = createNode(1);
	root->left = createNode(1);
	root->right = createNode(1);
	root->left->left = createNode(1);
	root->left->right = createNode(1);
	root->right->right = createNode(1);

	printf("%d\n", isUnivalTree(root));

	free(root->left->left);
	free(root->left->right);
	free(root->right->right);
	free(root->left);
	free(root->right);
	free(root);

	return 0;
}