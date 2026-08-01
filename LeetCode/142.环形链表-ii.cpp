/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

#include <unordered_set>

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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 3ms
// Floyd判环法
// class Solution
// {
//   public:
//     ListNode* detectCycle(ListNode* head)
//     {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast)
//             {
//                 while (slow != head)
//                 {
//                     head = head->next;
//                     slow = slow->next;
//                 }
//                 return slow;
//             }
//         }
//         return nullptr;
//     }
// };

// 17ms
// 哈希
class Solution
{
  public:
    ListNode* detectCycle(ListNode* head)
    {
        unordered_set<ListNode*> vis;
        while (head)
        {
            if (vis.count(head)) return head;
            vis.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// @lc code=end
