#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//左孩子右兄弟表示法
typedef struct node
{
	char data;
	struct node* lchild;
	struct node* rsibling;
} Node;

//双亲孩子表示法
typedef struct
{
	char data;
	int parent;
	Node* firstchild;
} PNode;

//孩子兄弟表示法
typedef struct
{
	char data;
	struct CSNode* firstchild;
	struct CSNode* rightsibling;
} CSNode;