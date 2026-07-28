/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

#include <functional>

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
// 一次遍历，O(n)
// class Solution
// {
//   public:
//     ListNode* reverseBetween(ListNode* head, int left, int right)
//     {
//         while (!head->next) return head;
//         ListNode dummy(0, head);
//         ListNode *prev = &dummy, *cur = head;
//         while (--left)
//         {
//             prev = prev->next;
//             cur = cur->next;
//             --right;
//         }
//         ListNode* before = prev;
//         while (right--)
//         {
//             ListNode* nxt = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = nxt;
//         }
//         before->next->next = cur;
//         before->next = prev;
//         return dummy.next;
//     }
// };

// 0ms
// 递归 O(n)
// between主要是向右递归找到翻转头
// 找到之后交给front处理就行
class Solution
{
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left == 1)
        {
            auto reverseFront = [&](this auto&& reverseFront, ListNode* head, int n) -> ListNode*
            {
                if (n == 1) return head;
                ListNode* last = reverseFront(head->next, n - 1);
                ListNode* rear = head->next->next;
                head->next->next = head;
                head->next = rear;
                return last;
            };
            return reverseFront(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};

// @lc code=end
