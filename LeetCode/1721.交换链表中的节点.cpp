/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 */

#include <vector>

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

// 12ms
// 转数组换值
// class Solution
// {
//   public:
//     ListNode* swapNodes(ListNode* head, int k)
//     {
//         vector<ListNode*> nodes(1, nullptr);
//         for (ListNode* cur = head; cur; cur = cur->next) nodes.emplace_back(cur);
//         swap(nodes[k]->val, nodes[nodes.size() - k]->val);
//         return head;
//     }
// };

// 0ms
// 双指针换值
class Solution
{
  public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *fast = head, *slow = head;
        while (k-- != 1) fast = fast->next;
        ListNode* left = fast;
        while (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        swap(left->val, slow->val);
        return head;
    }
};

// @lc code=end
