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
	//¶ÏÑÔ
	ListNode* newnode = BuyListNode(x);
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next->prev = newnode;
	phead->next = newnode;
}

//Î²É¾
void ListPopBack(ListNode* phead)
{
	//¶ÏÑÔ
	assert(phead);
	ListNode* tail = phead->prev;
	ListNode* prev = tail->prev;
	prev->next = phead;
	phead->prev = prev;
	free(tail);
}
//Í·É¾
void ListPopFront(ListNode* phead)
{
	//¶ÏÑÔ
	assert(phead);
	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
}

//²éÕÒ
ListNode* ListFind(ListNode* phead, LTDataType x)
{
	//¶ÏÑÔ
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//ÔÚposÎ»ÖÃÖ®ºó²åÈëx
void ListInsert(ListNode* pos, LTDataType x)
{
	//¶ÏÑÔ
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}
//É¾³ýposÎ»ÖÃµÄ½Úµã
void ListErase(ListNode* pos)
{
	//¶ÏÑÔ
	assert(pos);
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	prev->next = next;
	next->prev = prev;
	free(pos);
}