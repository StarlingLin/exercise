/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
// 迭代
// class Solution
// {
//   public:
//     ListNode* swapPairs(ListNode* head)
//     {
//         if (!head || !head->next) return head;
//         ListNode dummy(0, head);
//         ListNode *pre = &dummy, *cur = head;
//         while (cur && cur->next)
//         {
//             ListNode* nxt = cur->next;
//             ListNode* aft = nxt->next;
//             nxt->next = cur;
//             cur->next = aft;
//             pre->next = nxt;
//             pre = cur;
//             cur = aft;
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 递归
class Solution
{
  public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};

// @lc code=end
