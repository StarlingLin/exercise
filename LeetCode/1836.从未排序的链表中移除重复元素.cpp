/*
 * @lc app=leetcode.cn id=1836 lang=cpp
 *
 * [1836] 从未排序的链表中移除重复元素
 */

#include <unordered_map>

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

// 138ms
// 哈希 O(n)
// class Solution
// {
//   public:
//     ListNode* deleteDuplicatesUnsorted(ListNode* head)
//     {
//         ListNode dummy(0, head);
//         ListNode* cur = &dummy;
//         unordered_map<int, int> times;
//         while (cur->next)
//         {
//             ++times[cur->next->val];
//             cur = cur->next;
//         }
//         cur = &dummy;
//         while (cur->next)
//         {
//             if (times[cur->next->val] > 1)
//             {
//                 // ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 // delete tmp;
//             }
//             else
//                 cur = cur->next;
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 考虑到val范围在1~1e5
class Solution
{
  public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head)
    {
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        int times[100001] = {0};
        while (cur->next)
        {
            ++times[cur->next->val];
            cur = cur->next;
        }
        cur = &dummy;
        while (cur->next)
        {
            if (times[cur->next->val] > 1)
            {
                // ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                // delete tmp;
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};

// @lc code=end
