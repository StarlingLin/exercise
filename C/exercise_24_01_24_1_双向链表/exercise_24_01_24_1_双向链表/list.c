#define _CRT_SECURE_NO_WARNING

#include "List.h"

//ÉêÇë½Úµã
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

//³õÊ¼»¯Á´±í
ListNode* ListInit(void)
{
	ListNode* phead = BuyListNode((LTDataType)0);
	phead->next = phead->prev = phead;
	return phead;
}
//Ïú»ÙÁ´±í
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

//´òÓ¡
void ListPrint(ListNode* phead)
{
	//¶ÏÑÔ
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

//Î²²å
void ListPushBack(ListNode * phead, LTDataType x)
{
	//¶ÏÑÔ
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;
	phead->prev = newnode;
}
//Í·²å
void ListPushFront(ListNode* phead, LTDataType x)
{

}