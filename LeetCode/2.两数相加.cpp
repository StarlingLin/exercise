/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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

// 8ms
// 一次创建一次进位
// class Solution
// {
//   public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         ListNode *lh = new ListNode(), *cur1 = l1, *cur2 = l2, *cur = lh;
//         int sum = 0, flag = 0;
//         while (cur1 && cur2)
//         {
//             sum = cur1->val + cur2->val;
//             cur->next = new ListNode(sum);
//             cur1 = cur1->next;
//             cur2 = cur2->next;
//             cur = cur->next;
//         }
//         if (!cur1)
//         {
//             while (cur2)
//             {
//                 cur->next = new ListNode(cur2->val);
//                 cur2 = cur2->next;
//                 cur = cur->next;
//             }
//         }
//         if (!cur2)
//         {
//             while (cur1)
//             {
//                 cur->next = new ListNode(cur1->val);
//                 cur1 = cur1->next;
//                 cur = cur->next;
//             }
//         }
//         cur->next = nullptr;
//         cur = lh->next;
//         while (cur)
//         {
//             cur->val += flag;
//             flag = 0;
//             if (cur->val > 9)
//             {
//                 cur->val -= 10;
//                 flag = 1;
//             }
//             if (!cur->next && flag)
//             {
//                 cur->next = new ListNode(1);
//                 flag = 0;
//             }
//             cur = cur->next;
//         }
//         return lh->next;
//     }
// };

// 4ms
// 一次遍历解决
// class Solution
// {
//   public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         ListNode *lh = new ListNode(), *cur1 = l1, *cur2 = l2, *cur = lh;
//         int sum = 0, flag = 0;
//         while (cur1 || cur2 || flag)
//         {
//             sum = flag;
//             if (cur1)
//             {
//                 sum += cur1->val;
//                 cur1 = cur1->next;
//             }
//             if (cur2)
//             {
//                 sum += cur2->val;
//                 cur2 = cur2->next;
//             }
//             cur->next = new ListNode(sum % 10);
//             cur = cur->next;
//             flag = sum / 10;
//         }
//         return lh->next;
//     }
// };

// 3ms
// 迭代
// class Solution
// {
//   public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
//     {
//         if (!l1 && !l2) return nullptr;
//         if (!l1) return l2;
//         if (!l2) return l1;
//         int sum = l1->val + l2->val;
//         ListNode* ret = new ListNode(sum % 10);
//         ret->next = addTwoNumbers(l1->next, l2->next);
//         if (sum >= 10) ret->next = addTwoNumbers(ret->next, new ListNode(1));
//         return ret;
//     }
// };

// 0ms
// 一次遍历小改
class Solution
{
  public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode lh, *cur = &lh;
        int flag = 0;
        while (l1 || l2 || flag)
        {
            int sum = flag;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            flag = sum / 10;
        }
        return lh.next;
    }
};

// @lc code=end
