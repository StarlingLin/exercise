#define _CRT_SECURE_NO_WARNINGS

//两个无环单链表，返回第一个相交节点，如果不相交返回NULL

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;

		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;

		while (p1 != p2)
		{
			p1 = (p1 == NULL) ? pHead2 : p1->next;
			p2 = (p2 == NULL) ? pHead1 : p2->next;
		}

		return p1;
	}
};