#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//�������ֵܱ�ʾ��
typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rsibling;
} Node;

//˫�׺��ӱ�ʾ��
typedef struct
{
	char data;
	int parent;
	Node* firstchild;
} PNode;

//�����ֵܱ�ʾ��
typedef struct
{
	char data;
	struct CSNode* firstchild;
	struct CSNode* rightsibling;
} CSNode;