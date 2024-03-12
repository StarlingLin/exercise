#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node* next;
	struct Node* random;
};

//节点拆分
struct Node* copyRandomList1(struct Node* head) 
{
    if (head == NULL) 
    {
        return NULL;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next)
    {
        struct Node* nodeNew = malloc(sizeof(struct Node));
        nodeNew->val = node->val;
        nodeNew->next = node->next;
        node->next = nodeNew;
    }
    for (struct Node* node = head; node != NULL; node = node->next->next)
    {
        struct Node* nodeNew = node->next;
        nodeNew->random = (node->random != NULL) ? node->random->next : NULL;
    }
    struct Node* headNew = head->next;
    for (struct Node* node = head; node != NULL; node = node->next) 
    {
        struct Node* nodeNew = node->next;
        node->next = node->next->next;
        nodeNew->next = (nodeNew->next != NULL) ? nodeNew->next->next : NULL;
    }
    return headNew;
}

//暴力
void PushBack(struct Node** head, int val)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->val = val;
	new_node->next = NULL;
	new_node->random = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		struct Node* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = new_node;
	}
}
int GetIndex(struct Node* head, struct Node* node)
{
	if (node == NULL)
	{
		return -1;
	}
	int index = 0;
	struct Node* cur = head;
	while (cur)
	{
		if (cur == node)
		{
			return index;
		}
		cur = cur->next;
		++index;
	}
	return -1;
}
struct Node* GetNode(struct Node* head, int index)
{
	if (index < 0)
	{
		return NULL;
	}
	struct Node* cur = head;
	while (cur && index)
	{
		cur = cur->next;
		--index;
	}
	return cur;
}
struct Node* copyRandomList2(struct Node* head) 
{
    if (head == NULL) 
	{
		return NULL;
	}
    struct Node* headNew = malloc(sizeof(struct Node));
	headNew->val = head->val;
    headNew->next = NULL;
    headNew->random = NULL;
    struct Node* cur = head->next;
    while (cur != NULL)
    {
		PushBack(&headNew, cur->val);
		cur = cur->next;
	}
	struct Node* curNew = headNew;
	cur = head;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		{
			int index = GetIndex(head, cur->random);
			curNew->random = GetNode(headNew, index);
		}
		cur = cur->next;
		curNew = curNew->next;
	}
	return headNew;
}

int main()
{
	struct Node* head = NULL;
	PushBack(&head, 7);
	PushBack(&head, 13);
	PushBack(&head, 11);
	PushBack(&head, 10);
	PushBack(&head, 1);
	head->random = NULL;
	head->next->random = head;
	head->next->next->random = head->next->next->next->next;
	head->next->next->next->random = head->next->next;
	head->next->next->next->next->random = head;
	struct Node* headNew = copyRandomList2(head);
	struct Node* cur = headNew;
	while (cur)
	{
		printf("%d,", cur->val);
		if (cur->random)
		{
			printf("%d ", GetIndex(headNew, cur->random));
		}
		else
		{
			printf("NULL ");
		}
		cur = cur->next;
	}
	printf("\n");
	return 0;
}