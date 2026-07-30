/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// 快慢指针 O(n)
// class Solution
// {
//   public:
//     bool isPalindrome(ListNode* head)
//     {
//         if (!head->next) return true;
//         ListNode *slow = head, *fast = head;
//         while (fast->next && fast->next->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode *pre = nullptr, *cur = slow->next;
//         while (cur)
//         {
//             ListNode* nxt = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = nxt;
//         }
//         slow->next = nullptr;
//         ListNode *l = head, *r = pre;
//         while (r && l->val == r->val)
//         {
//             l = l->next;
//             r = r->next;
//         }
//         if (r) return false;
//         return true;
//     }
// };

// 10ms
// 递归
// if (!self(right->next)) return false;
// 从递归模板（归途处理|参与计算）简化而来：
// if (!right) return true;         终止条件-到链表尾返回成功
// bool result = self(right->next); 子递归结果参与当前层计算
// if (!result) return false;       子递归失败则直接向上传递
class Solution
{
  public:
    bool isPalindrome(ListNode* head)
    {
        ListNode* left = head;
        return [&](this auto&& self, ListNode* right) -> bool
        {
            if (!right) return true;
            if (!self(right->next)) return false;
            if (left->val != right->val) return false;
            left = left->next;
            return true;
        }(head);
    }
};

// @lc code=end
