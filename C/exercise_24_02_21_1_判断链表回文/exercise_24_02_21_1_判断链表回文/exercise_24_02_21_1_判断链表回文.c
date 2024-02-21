#define _CRT_SECURE_NO_WARNINGS

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
	int val;
	struct ListNode* next;
} ListNode;

bool isPalindrome(ListNode* head)
{
if (head == NULL || head->next == NULL)
	{
		return true;
	}
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	ListNode* pre = slow;
	ListNode* cur = slow->next;
	ListNode* temp;
	while (cur->next != NULL)
	{
		temp = cur->next;
		cur->next = temp->next;
		temp->next = pre->next;
		pre->next = temp;
	}
	ListNode* p1 = head;
	ListNode* p2 = pre->next;
	while (p1 != NULL && p2 != NULL)
	{
		if (p1->val != p2->val)
		{
			return false;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return true;

}

int main()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 1;
	head->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->val = 2;
	head->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->val = 3;
	head->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->val = 2;
	head->next->next->next->next = (ListNode*)malloc(sizeof(ListNode));
	head->next->next->next->next->val = 1;
	head->next->next->next->next->next = NULL;
	printf("%s\n", isPalindrome(head) ? "true" : "false");
	return 0;
}