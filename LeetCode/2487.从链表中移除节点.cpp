/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] 从链表中移除节点
 */

#include <limits>
#include <stack>

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

// TLE
// class Solution
// {
//   public:
//     ListNode* removeNodes(ListNode* head)
//     {
//         bool flag = true;
//         ListNode dummy(0, head);
//         ListNode* cur = nullptr;
//         while (flag)
//         {
//             flag = false;
//             cur = &dummy;
//             while (cur->next->next)
//             {
//                 if (cur->next->val < cur->next->next->val)
//                 {
//                     // ListNode* tmp = cur->next;
//                     cur->next = cur->next->next;
//                     // delete tmp;
//                     flag = true;
//                 }
//                 else
//                     cur = cur->next;
//             }
//         }
//         return dummy.next;
//     }
// };

// 12ms
// 递归
// class Solution
// {
//   public:
//     ListNode* removeNodes(ListNode* head)
//     {
//         if (!head->next) return head;
//         ListNode* cmpNode = removeNodes(head->next);
//         if (cmpNode->val > head->val) return cmpNode;
//         head->next = cmpNode;
//         return head;
//     }
// };

// 11ms
// 反转链表
// class Solution
// {
//   public:
//     ListNode* reverse(ListNode* head)
//     {
//         ListNode *pre = nullptr, *cur = head;
//         while (cur)
//         {
//             ListNode* next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         return pre;
//     }

//     ListNode* removeNodes(ListNode* head)
//     {
//         head = reverse(head);
//         ListNode* cur = head;
//         while (cur->next)
//         {
//             if (cur->val > cur->next->val)
//                 cur->next = cur->next->next;
//             else
//                 cur = cur->next;
//         }
//         return reverse(head);
//     }
// };

// 18ms
// 单调栈
class Solution
{
  public:
    ListNode* removeNodes(ListNode* head)
    {
        stack<ListNode*> st;
        ListNode* cur = head;
        while (cur)
        {
            while (!st.empty() && cur->val > st.top()->val) st.pop();
            if (st.empty())
                head = cur;
            else
                st.top()->next = cur;
            st.push(cur);
            cur = cur->next;
        }
        return head;
    }
};

// @lc code=end
