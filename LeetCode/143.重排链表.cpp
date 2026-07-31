/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

#include <algorithm>
#include <limits>

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
// 双指针
// class Solution
// {
//   public:
//     void reorderList(ListNode* head)
//     {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         ListNode *pre = nullptr, *cur = slow;
//         while (cur)
//         {
//             ListNode* nxt = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//         } // pre即为后半反转链表头

//         while (pre->next)
//         {
//             ListNode *lnxt = head->next, *rnxt = pre->next;
//             head->next = pre;
//             pre->next = lnxt;
//             head = lnxt;
//             pre = rnxt;
//         }
//     }
// };

// 0ms
// 递归
// 从递归模板（归途处理|短路传播）简化而来
class Solution
{
  public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next) return;
        ListNode* l = head;
        [&](this auto&& rev, ListNode* r) -> bool
        {
            if (!r) return true;
            if (!rev(r->next)) return false;
            if (l == r || l->next == r)
            {
                r->next = nullptr;
                return false;
            }
            ListNode* lnxt = l->next;
            l->next = r;
            r->next = lnxt;
            l = lnxt;
            return true;
        }(head->next);
    }
};

// @lc code=end
