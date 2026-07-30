/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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
// 迭代 O(n)
// 快慢指针找中点后反转后半罢了
// class Solution
// {
//   public:
//     int pairSum(ListNode* head)
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
//         }
//         int mxsum = INT_MIN;
//         while (pre)
//         {
//             mxsum = max(mxsum, head->val + pre->val);
//             head = head->next;
//             pre = pre->next;
//         }
//         return mxsum;
//     }
// };

// 8ms
// 递归
// 递归模板（归途处理|不参与计算）
class Solution
{
  public:
    int pairSum(ListNode* head)
    {
        int mxsum = INT_MIN;
        ListNode* l = head;
        [&](this auto&& rec, ListNode* r) -> void
        {
            if (r->next) rec(r->next);
            mxsum = max(mxsum, l->val + r->val);
            l = l->next;
        }(head);
        return mxsum;
    }
};

// @lc code=end
