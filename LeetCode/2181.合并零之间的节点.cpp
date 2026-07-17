/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
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

// 61ms
// 直接模拟，生成和节点插入到left后面
// class Solution
// {
//   public:
//     ListNode* mergeNodes(ListNode* head)
//     {
//         int sum = 0;
//         struct ListNode *cur = head->next, *left = head;
//         while (cur)
//         {
//             if (!cur->val)
//             {
//                 left->next = new ListNode(sum);
//                 left = left->next;
//                 sum = 0;
//             }
//             else
//                 sum += cur->val;
//             cur = cur->next;
//         }
//         return head->next;
//     }
// };

// 4ms
// 原地合并。后面的节点不是零就值加进来然后丢到；如果是零就丢到后开始新过程。
// class Solution
// {
//   public:
//     ListNode* mergeNodes(ListNode* head)
//     {
//         struct ListNode* cur = head->next;
//         while (cur)
//         {
//             while (cur->next && cur->next->val)
//             {
//                 cur->val += cur->next->val;
//                 cur->next = cur->next->next;
//             }
//             if (cur->next) cur->next = cur->next->next;
//             cur = cur->next;
//         }
//         return head->next;
//     }
// };

// 3ms
class Solution
{
  public:
    ListNode* mergeNodes(ListNode* head)
    {
        struct ListNode *cur = head->next, *tail = head;
        while (cur->next)
        {
            if (cur->val)
                tail->val += cur->val;
            else
            {
                tail = tail->next;
                tail->val = 0;
            }
            cur = cur->next;
        }
        tail->next = nullptr;
        return head;
    }
};

// @lc code=end
