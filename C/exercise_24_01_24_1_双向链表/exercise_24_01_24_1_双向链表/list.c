#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//³õÊ¼»¯Á´±í
ListNode* ListInit(void)
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	if (phead == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
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

//Î²²å
void ListPushBack(ListNode * phead, LTDataType x)
{
	//¶ÏÑÔ
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	newnode->data = x;
	newnode->next = phead;
	newnode->prev = tail;
	tail->next = newnode;
	phead->prev = newnode;
})