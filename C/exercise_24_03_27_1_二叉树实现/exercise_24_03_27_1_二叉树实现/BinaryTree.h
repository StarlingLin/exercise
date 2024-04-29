#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// ����������
void BinaryTreeDestroy(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
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
// �������ľ���
void BinaryTreeMirror(BTNode* root);
//�ж������������Ƿ���ͬ
_Bool BinaryTreeIsSame(BTNode* root1, BTNode* root2);
// �ж϶������Ƿ�Ϊ��һ��������������
_Bool BinaryTreeIsSubtree(BTNode* root1, BTNode* root2);
