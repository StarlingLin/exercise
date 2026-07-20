/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

// 7ms
// class Solution
// {
//   public:
//     void deleteNode(ListNode* node)
//     {
//         node->val = node->next->val;
//         ListNode* tmp = node->next;
//         node->next = node->next->next;
//         delete tmp;
//     }
// };

// 3ms
// 不回收内存
class Solution
{
  public:
    void deleteNode(ListNode* node)
    { *node = *node->next; }
};

// @lc code=end
