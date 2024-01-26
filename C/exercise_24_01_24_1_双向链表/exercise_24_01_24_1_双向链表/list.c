#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//³õÊ¼»¯Á´±í
void ListInit(ListNode** pphead)
{
	//¶ÏÑÔ
	assert(pphead);
	*pphead = (ListNode*)malloc(sizeof(ListNode));
	if (*pphead == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	(*pphead)->next = NULL;
	(*pphead)->prev = NULL;
}