#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
	{
		return NULL;
	}

	for (struct Node* cur = head; cur != NULL; cur = cur->next->next)
	{
		struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->val = cur->val;
		newNode->next = cur->next;
		cur->next = newNode;
	}
	for (struct Node* cur = head; cur != NULL; cur = cur->next->next)
	{
		struct Node* newNode = cur->next;
		newNode->random = (cur->random != NULL) ? cur->random->next : NULL;
	}
	struct Node* newHead = head->next;
	for (struct Node* cur = head; cur != NULL; cur = cur->next)
	{
		struct Node* newNode = cur->next;
		cur->next = cur->next->next;
		cur->next = (newNode->next != NULL) ? newNode->next : NULL;
	}

	return newHead;
}