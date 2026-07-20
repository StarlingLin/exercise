/*
 * @lc app=leetcode.cn id=3062 lang=cpp
 *
 * [3062] 链表游戏的获胜者
 */

#include <string>

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
class Solution
{
  public:
    string gameResult(ListNode* head)
    {
        size_t odd = 0, even = 0;
        while (head && head->next)
        {
            if (head->val < head->next->val) ++odd;
            if (head->val > head->next->val) ++even;
            head = head->next->next;
        }
        if (odd > even)
            return "Odd";
        else if (odd < even)
            return "Even";
        else
            return "Tie";
    }
};
// @lc code=end
