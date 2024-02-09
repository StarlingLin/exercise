#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements1(struct ListNode* head, int val)
{
	struct ListNode* p = head;
	struct ListNode* q = NULL;
	while (p != NULL) {
		if (p->val == val) {
			if (q == NULL) {
				head = p->next;
				free(p);
				p = head;
			}
			else {
				q->next = p->next;
				free(p);
				p = q->next;
			}
		}
		else {
			q = p;
			p = p->next;
		}
	}
	return head;
}

struct ListNode* removeElements2(struct ListNode* head, int val) {
	if (!head)
		return NULL;
	struct ListNode* pcur = head;
	while (pcur->next)
	{
		if (pcur->next->val == val)
		{
			struct ListNode* next = pcur->next->next;
			free(pcur->next);
			pcur->next = next;
		}
		else
		{
			pcur = pcur->next;
		}
	}
	if (head->val == val)
	{
		pcur = head;
		head = head->next;
		free(pcur);
	}
	return head;
}

int main()
{
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->val = 2;
	head->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->val = 6;
	head->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->val = 3;
	head->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->next->val = 4;
	head->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->next->next->val = 5;
	head->next->next->next->next->next->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next->next->next->next->next->next->val = 6;
	head->next->next->next->next->next->next->next = NULL;

	struct ListNode* p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");

	head = removeElements1(head, 6);

	p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");

	head = removeElements2(head, 5);

	p = head;
	while (p != NULL) {
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");

	return 0;
}