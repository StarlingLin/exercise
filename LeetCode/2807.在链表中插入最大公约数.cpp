/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
 */

#include <numeric>

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

// 3ms
// O(n*log(U)) n为节点数，U为节点最大值，logU求gcd
// class Solution {
// public:
//     ListNode* insertGreatestCommonDivisors(ListNode* head) {
//         ListNode* cur = head;
//         while (cur && cur->next)
//         {
//             int num = gcd(cur->val, cur->next->val);
//             ListNode* ins = new ListNode(num, cur->next);
//             cur->next = ins;
//             cur = cur->next->next;
//         }
//         return head;
//     }
// };

// 简写
class Solution
{
  public:
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        ListNode* cur = head;
        while (cur->next)
        {
            cur->next = new ListNode(gcd(cur->val, cur->next->val), cur->next);
            cur = cur->next->next;
        }
        return head;
    }
};

// @lc code=end
