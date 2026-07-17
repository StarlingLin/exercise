/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 *
 * [2058] 找出临界点之间的最小和最大距离
 */

#include <limits>
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
// 一次遍历，记录最早的临界点和最近的临界点
class Solution
{
  public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        int mindis = -1, maxdis = -1, pos = 1, firstpos = 0, nearpos = 0;
        while (head->next && head->next->next)
        {
            int pre = head->val;
            int cur = head->next->val;
            int post = head->next->next->val;
            if ((cur > pre && cur > post) || (cur < pre && cur < post))
            {
                maxdis = firstpos ? pos - firstpos : maxdis;
                mindis = nearpos ? min(pos - nearpos, (mindis + 1) ? mindis : INT_MAX) : mindis;
                firstpos = firstpos ? firstpos : pos;
                nearpos = pos;
            }
            head = head->next;
            ++pos;
        }
        return {mindis, maxdis};
    }
};
// @lc code=end
