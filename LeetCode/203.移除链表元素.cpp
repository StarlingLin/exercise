/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val)
    {
        if (!head) return nullptr;
        ListNode dummy(0, head);
        ListNode* p = &dummy;
        while (p && p->next)
        {
            while (p->next && p->next->val == val)
            {
                ListNode* tmp = p->next;
                p->next = p->next->next;
                delete tmp;
            }
            p = p->next;
        }
        return dummy.next;
    }
};
// @lc code=end
