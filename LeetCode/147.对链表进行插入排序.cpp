/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

using namespace std;

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
// 插排
class Solution
{
  public:
    ListNode* insertionSortList(ListNode* head)
    {
        if (!head) return head;
        ListNode dummy(0, head);
        ListNode *tail = head, *cur = head->next, *ins = nullptr;
        while (cur)
        {
            if (tail->val <= cur->val)
                tail = tail->next;
            else
            {
                ins = &dummy;
                while (ins->next->val <= cur->val) ins = ins->next;
                tail->next = cur->next;
                cur->next = ins->next;
                ins->next = cur;
            }
            cur = tail->next;
        }
        return dummy.next;
    }
};
// @lc code=end
