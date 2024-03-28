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

}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root);
// �������������
void BinaryTreeInOrder(BTNode* root);
// �������������
void BinaryTreePostOrder(BTNode* root);
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);