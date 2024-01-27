#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//初始化链表
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
//销毁链表
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
