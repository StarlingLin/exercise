/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
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

// 211ms
// 直接模拟，O(m+n)
// class Solution
// {
//   public:
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
//     {
//         ListNode* cur = list1;
//         while (a-- != 1)
//         {
//             cur = cur->next;
//             b--;
//         }
//         ListNode* rm = cur;
//         while (b--)
//         {
//             // ListNode* tmp = rm;
//             rm = rm->next;
//             // delete tmp;
//         }
//         cur->next = list2;
//         while (cur->next) cur = cur->next;
//         cur->next = rm->next;
//         return list1;
//     }
// };

// 区别不大
class Solution
{
  public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode *cur = list1, *l = nullptr, *r = nullptr;
        for (int i = 0; cur->next; ++i, cur = cur->next)
        {
            if (i + 1 == a) l = cur;
            if (i == b) r = cur->next;
        }
        cur = list2;
        while (cur->next) cur = cur->next;
        l->next = list2;
        cur->next = r;
        return list1;
    }
};

// @lc code=end
