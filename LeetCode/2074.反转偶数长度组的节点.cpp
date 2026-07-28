/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
 */

#include <vector>

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
// 递归 O(n)
// 这题递归就直接把第25题的稍微改一下就行，很简单
// 已知等差数列和求变量，因此空间复杂度为O(√n)
// class Solution
// {
//   public:
//     ListNode* reverseEvenK(ListNode* head, int k)
//     {
//         if (!head) return nullptr;
//         int len = 0;
//         ListNode *knext = head, *kth;
//         while (knext && len < k)
//         {
//             kth = knext;
//             knext = knext->next;
//             ++len;
//         }
//         ListNode* pre = reverseEvenK(knext, k + 1);
//         if (len % 2)
//         {
//             kth->next = pre;
//             return head;
//         }
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
//
//     ListNode* reverseEvenLengthGroups(ListNode* head)
//     { return reverseEvenK(head, 1); }
// };

// 3ms
// 改成迭代
// class Solution
// {
//   public:
//     ListNode* reverseEvenLengthGroups(ListNode* head)
//     {
//         ListNode dummy(0, head);
//         // 跨循环保持量
//         ListNode* previous = &dummy;
//         int k = 1;
//         // 迭代，基本和递归部分一致
//         while (previous->next) // previous->next等价递归head
//         {
//             int len = 0;
//             ListNode *knext = previous->next, *kth;
//             while (knext && len < k)
//             {
//                 kth = knext;
//                 knext = knext->next;
//                 ++len;
//             }
//             if (len % 2)
//                 previous = kth;
//             else
//             {
//                 ListNode* cur = previous->next;
//                 ListNode* pre = knext;
//                 ListNode* tail = cur;
//                 while (cur != knext)
//                 {
//                     ListNode* nxt = cur->next;
//                     cur->next = pre;
//                     pre = cur;
//                     cur = nxt;
//                 }
//                 // 修改保持量
//                 previous->next = pre;
//                 previous = tail;
//             }
//             ++k;
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 构造数组，交换元素值
// 这题没有禁止交换元素值
class Solution
{
  public:
    ListNode* reverseEvenLengthGroups(ListNode* head)
    {
        vector<ListNode*> nodes;
        ListNode* node = head;
        size_t k = 1;
        while (node)
        {
            nodes.emplace_back(node);
            size_t len = nodes.size();
            if (len == k || !node->next)
            {
                if (len % 2 == 0)
                    for (int i = 0; i < len / 2; ++i) swap(nodes[i]->val, nodes[len - i - 1]->val);
                nodes.clear();
                ++k;
            }
            node = node->next;
        }
        return head;
    }
};

// @lc code=end
