#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    struct ListNode* pnew = NULL;
    struct ListNode* pcur = NULL;
    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    while (p1 && p2)
    {
        if (p1->val <= p2->val)
        {
            if (!pnew)
            {
                pnew = pcur = p1;
            }
            else
            {
                pcur->next = p1;
                pcur = pcur->next;
            }
            p1 = p1->next;
        }
        else
        {
            if (!pnew)
            {
                pnew = pcur = p2;
            }
            else
            {
                pcur->next = p2;
                pcur = pcur->next;
            }
            p2 = p2->next;
        }
    }
    if (p1)
    {
        pcur->next = p1;
    }
    if (p2)
    {
        pcur->next = p2;
    }
    return pnew;
}

int main()
{
	return 0;
}