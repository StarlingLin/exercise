#define _CRT_SECURE_NO_WARNINGS

//���������ÿһ���ڵ��ֵ����0-9֮�䣬��ô��������Ϳ��Դ���һ��������
//���磺9->3->7�����Դ�������937�����������������������Ǵ��������֮������

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