/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
// 迭代 O(n)
// class Solution
// {
//   public:
//     ListNode* reverseList(ListNode* head)
//     {
//         if (!head || !head->next) return head;
//         ListNode *pre = nullptr, *cur = head, *nxt = head->next;
//         while (cur)
//         {
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//             if (nxt) nxt = nxt->next;
//         }
//         return pre;
//     }
// };

// 0ms
// 递归
class Solution
{
  public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode* tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};

// @lc code=end
