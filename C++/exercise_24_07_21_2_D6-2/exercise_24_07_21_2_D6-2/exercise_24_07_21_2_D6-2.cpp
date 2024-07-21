#define _CRT_SECURE_NO_WARNINGS

//假设链表的每一个节点的值都在0-9之间，那么链表整体就可以代表一个整数。
//例如：9->3->7，可以代表整数937。给定两个这种链表，求他们代表的整数之和链表。

#include <iostream>

using namespace std;

class Solution 
{
public:
	ListNode* reverseList(ListNode* head)
	{
		ListNode* pre = nullptr;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* next = cur->next;
			cur->next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}

	ListNode* addInList(ListNode* head1, ListNode* head2)
	{
		ListNode* p1 = reverseList(head1);
		ListNode* p2 = reverseList(head2);
		ListNode* res = new ListNode(0);
		ListNode* p = res;
		int carry = 0;
		while (p1 || p2 || carry)
		{
			int sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
			carry = sum / 10;
			p->next = new ListNode(sum % 10);
			p = p->next;
			if (p1) p1 = p1->next;
			if (p2) p2 = p2->next;
		}
		return reverseList(res->next);
	}
};