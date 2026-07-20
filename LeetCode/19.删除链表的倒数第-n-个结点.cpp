/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
class Solution
{
  public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode dummy = ListNode(0, head);
        ListNode *left = &dummy, *right = left;
        while (n--) right = right->next;
        while (right->next)
        {
            left = left->next;
            right = right->next;
        }
        ListNode* tmp = left->next;
        left->next = left->next->next;
        delete tmp;
        return dummy.next;
    }
};
// @lc code=end
