/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 0ms
class Solution
{
  public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || !head->next || !k) return head;
        int len = 0;
        ListNode dummy(0, head);
        ListNode *beforeR = &dummy, *tail;
        for (tail = &dummy; tail->next; tail = tail->next) ++len;
        for (int i = 0; i < len - k % len; ++i) beforeR = beforeR->next;
        tail->next = dummy.next;
        dummy.next = beforeR->next;
        beforeR->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end
