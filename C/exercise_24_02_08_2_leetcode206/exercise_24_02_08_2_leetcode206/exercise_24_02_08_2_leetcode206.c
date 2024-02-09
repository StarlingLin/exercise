#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
} ListNode;

ListNode* reverseList(ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* next = NULL;

	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	return prev;
}

int main()
{
	return 0;
}