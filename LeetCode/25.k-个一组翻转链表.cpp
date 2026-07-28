// @before-stub-for-debug-begin
#include "commoncppproblem25.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
// 递归，翻转前k个，后面交给下一个自己解决 O(n)
// 但是空间复杂度也是O(n/k)，不符合题目进阶要求
// class Solution
// {
//   public:
//     ListNode* reverseKGroup(ListNode* head, int k)
//     {
//         int gap = k;
//         ListNode* knext = head;
//         while (knext && gap)
//         {
//             knext = knext->next;
//             --gap;
//         }
//         if (gap) return head;
//         ListNode *pre = nullptr, *cur = head;
//         while (cur != knext)
//         {
//             ListNode* nxt = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//         }
//         head->next = reverseKGroup(knext, k);
//         return pre;
//     }
// };

// 再简一下翻转
// class Solution
// {
//   public:
//     ListNode* reverseKGroup(ListNode* head, int k)
//     {
//         int gap = k;
//         ListNode* knext = head;
//         while (knext && gap)
//         {
//             knext = knext->next;
//             --gap;
//         }
//         if (gap) return head;
//         ListNode* pre = reverseKGroup(knext, k);
//         ListNode* cur = head;
//         while (cur != knext)
//         {
//             ListNode* nxt = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//         }
//         return pre;
//     }
// };

// 0ms
// 迭代模拟 O(n)
// 同时空间复杂度常数级符合进阶要求
class Solution
{
  public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode dummy(0, head);
        ListNode* previous = &dummy; // 记录上次循环尾
        while (true)
        {
            int gap = k;
            ListNode* knext = previous->next;
            while (knext && gap)
            {
                knext = knext->next;
                --gap;
            }
            if (gap) break;
            ListNode* cur = previous->next;
            ListNode* tail = cur;
            ListNode* pre = knext; // 这边先空再赋值一样的，和前面的优化一样
            while (cur != knext)   // 翻转[cur, knext)
            {
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            previous->next = pre;
            previous = tail;
        }
        return dummy.next;
    }
};

// @lc code=end
