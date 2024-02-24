#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode *slow = head;
	struct ListNode *fast = head;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			struct ListNode *slow2 = head;
			while (slow2 != slow)
			{
				slow = slow->next;
				slow2 = slow2->next;
			}
			return slow2;
		}
	}
	return NULL;
}
