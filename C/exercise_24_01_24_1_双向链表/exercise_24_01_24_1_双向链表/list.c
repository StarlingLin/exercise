#define _CRT_SECURE_NO_WARNINGS

#include "List.h"

//��ʼ������
void ListInit(ListNode** pphead)
{
	//����
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