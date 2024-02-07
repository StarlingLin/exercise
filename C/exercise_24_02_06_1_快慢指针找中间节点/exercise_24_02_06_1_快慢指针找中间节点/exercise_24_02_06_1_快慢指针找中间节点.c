#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* p1, * p2;
    p1 = p2 = head;
    while (p2 && p2->next)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    return p1;
}

int main()
{
    return 0;
}