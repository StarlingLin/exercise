#define _CRT_SECURE_NO_WARNING

#include "List.h"

//����ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	newnode->data = x;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

//��ʼ������
ListNode* ListInit(void)
{
	ListNode* phead = BuyListNode((LTDataType)0);
	phead->next = phead->prev = phead;
	return phead;
}
//��������
void ListDestory(ListNode** pphead)
{
	if (pphead == NULL)
	{
		return;
	}
	ListNode* phead = *pphead;
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	*pphead = NULL;
} 

//��ӡ
void ListPrint(ListNode* phead)
{
	//����
	assert(phead);
	ListNode* cur = phead->next;
	printf("head->");
	while (cur != phead)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("tail\n");
}

//β��
void ListPushBack(ListNode * phead, LTDataType x)
{
	//����
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;
	phead->prev = newnode;
}
//ͷ��
void ListPushFront(ListNode* phead, LTDataType x)
{

}