#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "BinaryTree.h"

int main()
{
	BTDataType a[] = "ABD##E#H##CF##G##";
	int n = sizeof(a) / sizeof(a[0]) - 1;
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, n, &i);
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("size = %d\n", BinaryTreeSize(root));
	printf("leaf size = %d\n", BinaryTreeLeafSize(root));
	printf("level k size = %d\n", BinaryTreeLevelKSize(root, 3));
	BTNode* node = BinaryTreeFind(root, 'H');
	if (node)
	{
		printf("find success\n");
	}
	else
	{
		printf("find failed\n");
	}
	BinaryTreeDestroy(&root);
	return 0;
}