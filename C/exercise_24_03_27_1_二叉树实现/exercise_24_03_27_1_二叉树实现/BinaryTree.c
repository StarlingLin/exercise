#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* new = (BTDataType*)malloc(sizeof(BTNode));
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
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi++] == '#')
	{
		return NULL;
	}
	BTNode* root = BuyBTNode(a[*pi++]);
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode** root)
{
	if (*root == NULL)
	{
		return;
	}
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(*root);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// ������Ҷ�ӽڵ����
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
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
// �������������
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
// �������
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
		printf("%c ", front->_data);
		QueuePop(&q);
		if (front->_left != NULL)
		{
			QueuePush(&q, front->_left);
		}
		if (front->_right != NULL)
		{
			QueuePush(&q, front->_right);
		}
	}
	printf("\n");

	QueueDestory(&q);
}
// �ж϶������Ƿ�����ȫ������
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
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
}