/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 8ms
// 快慢指针
// class Solution
// {
//   public:
//     bool hasCycle(ListNode* head)
//     {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//             if (slow == fast) return true;
//         }
//         return false;
//     }
// };

// 13ms
// 递归
class Solution
{
  public:
    bool hasCycle(ListNode* head)
    {
        if (!head || !head->next) return false;
        ListNode* nxt = head->next;
        if (nxt == head) return true;
        head->next = head;
        return hasCycle(nxt);
    }
};

// @lc code=end
