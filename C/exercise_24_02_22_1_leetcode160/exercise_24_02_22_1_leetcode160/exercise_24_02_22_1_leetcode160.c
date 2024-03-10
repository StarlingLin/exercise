#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//各自遍历一遍，如果有交点，最后一定会相遇并且相遇在交点，如果没有交点，最后一定会同时为NULL
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	struct ListNode* pA = headA;
	struct ListNode* pB = headB;

	while (pA != pB)
	{
		pA = pA ? pA->next : headB;
		pB = pB ? pB->next : headA;
	}

	return pA;
}

int main()
{
	struct ListNode* headA = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* headB = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));

	headA->val = 4;
	headA->next = node1;
	node1->val = 1;
	node1->next = node2;
	node2->val = 8;
	node2->next = node3;
	node3->val = 4;
	node3->next = node4;
	node4->val = 5;
	node4->next = NULL;

	headB->val = 5;
	headB->next = node5;
	node5->val = 0;
	node5->next = node6;
	node6->val = 1;
	node6->next = node2;

	struct ListNode* result = getIntersectionNode(headA, headB);
	printf("%d\n", result->val);

	free(headA);
	free(headB);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);

	return 0;
}