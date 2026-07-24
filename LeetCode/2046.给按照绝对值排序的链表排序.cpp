/*
 * @lc app=leetcode.cn id=2046 lang=cpp
 *
 * [2046] 给按照绝对值排序的链表排序
 */

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
// O(n)
// class Solution
// {
//   public:
//     ListNode* sortLinkedList(ListNode* head)
//     {
//         if (!head || !head->next) return head;
//         ListNode dummy(0, head);
//         ListNode* cur = &dummy;
//         while (cur->next)
//         {
//             if (cur->next == head || cur->next->val >= 0)
//                 cur = cur->next;
//             else
//             {
//                 ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 tmp->next = dummy.next;
//                 dummy.next = tmp;
//             }
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 上面那个判断条件写复杂了，第一个节点就算是负的也无所谓可以跳过
class Solution
{
  public:
    ListNode* sortLinkedList(ListNode* head)
    {
        if (!head || !head->next) return head;
        ListNode dummy(0, head);
        ListNode* cur = head;
        while (cur->next)
        {
            if (cur->next->val < 0)
            {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                tmp->next = dummy.next;
                dummy.next = tmp;
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};

// @lc code=end
