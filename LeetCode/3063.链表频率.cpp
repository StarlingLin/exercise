/*
 * @lc app=leetcode.cn id=3063 lang=cpp
 *
 * [3063] 链表频率
 */

#include <unordered_map>
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

// 11ms
class Solution
{
  public:
    ListNode* frequenciesOfElements(ListNode* head)
    {
        unordered_map<int, int> freq;
        while (head)
        {
            ++freq[head->val];
            head = head->next;
        }
        ListNode* h = new ListNode;
        ListNode* cur = h;
        for (auto i : freq)
        {
            cur->next = new ListNode(i.second);
            cur = cur->next;
        }
        cur->next = nullptr;
        return h->next;
    }
};
// @lc code=end
