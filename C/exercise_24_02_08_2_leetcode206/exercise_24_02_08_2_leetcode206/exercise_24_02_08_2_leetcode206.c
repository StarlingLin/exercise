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
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->val = 2;
	head->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->val = 3;
	head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->val = 4;
	head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->next->val = 5;
	head->next->next->next->next->next = NULL;

	ListNode* reversed = reverseList(head);

	while (reversed != NULL)
	{
		printf("%d ", reversed->val);
		reversed = reversed->next;
	}

	return 0;
}