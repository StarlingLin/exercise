#define _CRT_SECURE_NO_WARNINGS

//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

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

int main()
{
	struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->val = 3;
	head->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->val = 0;
	head->next->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
	head->next->next->next->val = -4;
	head->next->next->next->next = head->next;

	struct ListNode *result = detectCycle(head);
	printf("%d\n", result->val);

	free(head->next->next->next);
	free(head->next->next);
	free(head->next);
	free(head);

	return 0;
}

