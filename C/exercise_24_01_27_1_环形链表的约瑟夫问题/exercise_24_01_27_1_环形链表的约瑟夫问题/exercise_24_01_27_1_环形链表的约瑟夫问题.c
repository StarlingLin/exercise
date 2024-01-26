#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode *next;
} ListNode;

ListNode* BuyListNode(int x)
{
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	if (newNode == NULL)
	{
		perror("BuyListNode");
		exit(EXIT_FAILURE);
	}
	newNode->data = x;
	newNode->next = NULL;
}

ListNode* creatList(int n)
{
	ListNode* head = BuyListNode(1);
	ListNode* tail = head;
	for (int i = 2; i <= n; i++)
	{
		tail->next = BuyListNode(i);
		tail = tail->next;
	}
	//使其成为循环链表
	tail->next = head;
	return head;
}

int ysf(int n, int m)
{
	//创建不带头结点的单向循环链表
	ListNode* head = creatList(n);
	//逢m出列
	ListNode* cur = head;
	ListNode* prev = NULL;
	int cnt = 1;
	while (cur->next != cur)
	{
		if (cnt == m)
		{
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
			cnt = 1;
		}
		else
		{
			prev = cur;
			cur = cur->next;
			cnt++;
		}
	}
	return cur->data;
}

int main()
{
	printf("%d\n", ysf(10, 3));
	return 0;
}