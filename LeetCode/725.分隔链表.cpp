/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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

// 0ms
// 模拟
class Solution
{
  public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int total = 0;
        vector<ListNode*> ans(k, nullptr);
        for (ListNode* p = head; p; p = p->next) ++total;
        int split = total / k, diff = total % k;
        ListNode* cur = head;
        for (int i = 0; i < k && cur; ++i)
        {
            int len = split + (i < diff);
            ListNode* h = cur;
            for (int j = 0; j < len - 1; ++j) cur = cur->next;
            ListNode* tmp = cur;
            cur = cur->next;
            tmp->next = nullptr;
            ans[i] = h;
        }
        return ans;
    }
};
// @lc code=end
