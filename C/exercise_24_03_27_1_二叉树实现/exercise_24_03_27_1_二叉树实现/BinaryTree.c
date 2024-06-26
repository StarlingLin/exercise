#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* new = (BTNode*)malloc(sizeof(BTNode));
	if (new == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	new->_data = x;
	new->_left = NULL;
	new->_right = NULL;
	return new;
}
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (*pi >= n || a[*pi] == '#') 
	{
		(*pi)++; // 跳过当前的'#'或越界的元素
		return NULL;
	}
	BTNode* root = BuyBTNode(a[(*pi)++]);
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestroy(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestroy(&(*root)->_left);
	BinaryTreeDestroy(&(*root)->_right);
	free(*root);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->_data == x)
	{
		return root;
	}
	BTNode* ret = BinaryTreeFind(root->_left, x);
	if (ret != NULL)
	{
		return ret;
	}
	return BinaryTreeFind(root->_right, x);
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		printf("%c ", front->_data); // 直接打印当前节点的数据

		if (front->_left != NULL) 
		{
			QueuePush(&q, front->_left); // 只有非NULL节点才入队
		}
		if (front->_right != NULL) 
		{
			QueuePush(&q, front->_right); // 只有非NULL节点才入队
		}
	}
	printf("\n");

	QueueDestroy(&q);
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
		Queue q;
	QueueInit(&q);
	if (root != NULL)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->_left);
		QueuePush(&q, front->_right);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
		{
			QueueDestroy(&q);
			return 0;
		}
	}
	QueueDestroy(&q);
	return 1;
}

// 二叉树的镜像
void BinaryTreeMirror(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTNode* tmp = root->_left;
	root->_left = root->_right;
	root->_right = tmp;
	BinaryTreeMirror(root->_left);
	BinaryTreeMirror(root->_right);
}

//判断两个二叉树是否相同
_Bool BinaryTreeIsSame(BTNode* root1, BTNode* root2)
{
	if (root1 == NULL && root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL || root2 == NULL)
	{
		return false;
	}
	if (root1->_data != root2->_data)
	{
		return false;
	}
	return BinaryTreeIsSame(root1->_left, root2->_left) && BinaryTreeIsSame(root1->_right, root2->_right);
}

// 判断二叉树是否为另一个二叉树的子树
_Bool BinaryTreeIsSubtree(BTNode* root1, BTNode* root2)	// root1是大树，root2是小树
{	
	if (root2 == NULL)
	{
		return true;
	}
	if (root1 == NULL)
	{
		return false;
	}
	if (root1->_data == root2->_data)
	{
		if (BinaryTreeIsSame(root1, root2))
		{
			return true;
		}
	}
	return BinaryTreeIsSubtree(root1->_left, root2) || BinaryTreeIsSubtree(root1->_right, root2);
}