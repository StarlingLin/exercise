#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
 	struct ListNode *next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	if (pListHead == NULL || k <= 0)
	{
		return NULL;
	}
	struct ListNode* pfront = pListHead;
	struct ListNode* pback = pListHead;
	for (int i = 0; i < k - 1; ++i)
	{
		if (pfront->next == NULL)
		{
			return NULL;
		}
		pfront = pListHead->next;
	}
	while (pfront->next != NULL)
	{
		pfront = pfront->next;
		pback = pback->next;
	}
	return pback;
}



int main()
{
	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	p1->val = 1;
	p2->val = 2;
	p3->val = 3;
	p4->val = 4;
	p5->val = 5;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = NULL;
	struct ListNode* p = FindKthToTail(p1, 2);
	printf("%d\n", p->val);
	return 0;
}


//ANS
// 
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	if (pListHead == NULL || k <= 0)
//	{
//		return NULL;
//	}
//	struct ListNode* pa = pListHead;
//	struct ListNode* pb = pListHead;
//	for (int i = 0; i < k - 1; i++)
//	{
//		if (pa->next != NULL)
//		{
//			pa = pa->next;
//		}
//		else
//		{
//			return NULL;
//		}
//	}
//	while (pa->next != NULL)
//	{
//		pa = pa->next;
//		pb = pb->next;
//	}
//	return pb;
//}