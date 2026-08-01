/*
 * @lc app=leetcode.cn id=2674 lang=cpp
 *
 * [2674] 拆分循环链表
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

// 450ms
// 快慢指针 O(n)
// 已知节点数范围2~10^5
class Solution
{
  public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list)
    {
        ListNode *slow = list, *fast = list;
        while (fast->next != list && fast->next->next != list)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = slow->next;
        fast = (fast->next == list) ? fast : fast->next;
        fast->next = list2;
        slow->next = list;
        return {list, list2};
    }
};

// @lc code=end
