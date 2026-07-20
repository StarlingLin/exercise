/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) return head;
        ListNode* cur = head;
        while (cur->next)
        {
            if (cur->next->val == cur->val)
            {
                ListNode* tmp = cur->next;
                cur->next = tmp->next;
                delete tmp;
            }
            else
                cur = cur->next;
        }
        return head;
    }
};
// @lc code=end
