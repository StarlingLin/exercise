﻿#define _CRT_SECURE_NO_WARNINGS

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

//我们使用两个指针，fast 与 slow。它们起始都位于链表的头部。随后，slow 指针每次向后移动一个位置，而 fast 指针向后移动两个位置。如果链表中存在环，则 fast 指针最终将再次与 slow 指针在环中相遇。
//如下图所示，设链表中环外部分的长度为 a。slow 指针进入环后，又走了 b 的距离与 fast 相遇。此时，fast 指针已经走完了环的 n 圈，因此它走过的总距离为 a + n(b + c) + b = a + (n + 1)b + nca + n(b + c) + b = a + (n + 1)b + nca + n(b + c) + b = a + (n + 1)b + nc。
//根据题意，任意时刻，fast 指针走过的距离都为 slow 指针的 2 倍。因此，我们有a + (n + 1)b + nc = 2(a + b)  ⟹  a = c + (n−1)(b + c)
//有了 a = c + (n−1)(b + c) 的等量关系，我们会发现：从相遇点到入环点的距离加上 n−1 圈的环长，恰好等于从链表头部到入环点的距离。
//因此，当发现 slow 与 fast 相遇时，我们再额外使用一个指针 ptr。起始，它指向链表头部；随后，它和 slow 每次向后移动一个位置。最终，它们会在入环点相遇。