#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
} ListNode;

bool hasCycle(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
        {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 3;
	head->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->val = 2;
	head->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->val = 0;
	head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->val = -4;
	head->next->next->next->next = head->next;
	printf("%d\n", hasCycle(head));
	return 0;
}