/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
// O(n) 常规遍历删节点
// class Solution
// {
//   public:
//     ListNode* deleteDuplicates(ListNode* head)
//     {
//         ListNode dummy = ListNode(0, head);
//         ListNode* cur = &dummy;
//         while (cur->next && cur->next->next)
//         {
//             int val = cur->next->val;
//             if (cur->next->next->val == val)
//             {
//                 while (cur->next && cur->next->val == val)
//                 {
//                     // ListNode* tmp = cur->next;
//                     cur->next = cur->next->next;
//                     // delete tmp
//                 }
//             }
//             else
//                 cur = cur->next;
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 双指针，后指针向后遍历至不同值，前指针next更新
class Solution
{
  public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode dummy = ListNode(0, head);
        ListNode* cur = &dummy;
        while (cur->next && cur->next->next)
        {
            int val = cur->next->val;
            if (cur->next->next->val == val)
            {
                auto nxt = cur->next;
                while (nxt && nxt->val == val)
                {
                    // ListNode* tmp = nxt;
                    nxt = nxt->next;
                    // delete tmp;
                }
                cur->next = nxt;
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};

// @lc code=end
