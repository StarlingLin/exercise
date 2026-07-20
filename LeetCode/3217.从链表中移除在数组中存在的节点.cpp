/*
 * @lc app=leetcode.cn id=3217 lang=cpp
 *
 * [3217] 从链表中移除在数组中存在的节点
 */

#include <set>
#include <unordered_set>
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

// 直接用find()TLE了

// 183ms
// class Solution
// {
//   public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head)
//     {
//         set<int> occ(nums.begin(), nums.end());
//         ListNode dummy(0, head);
//         ListNode* cur = &dummy;
//         while (cur->next)
//         {
//             int key = cur->next->val;
//             if (occ.find(key) != occ.end())
//             {
//                 // ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 // delete tmp;
//             }
//             else
//                 cur = cur->next;
//         }
//         return dummy.next;
//     }
// };

// 103ms
// class Solution
// {
//   public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head)
//     {
//         unordered_set<int> occ(nums.begin(), nums.end());
//         ListNode dummy(0, head);
//         ListNode* cur = &dummy;
//         while (cur->next)
//         {
//             int key = cur->next->val;
//             if (occ.find(key) != occ.end())
//             {
//                 // ListNode* tmp = cur->next;
//                 cur->next = cur->next->next;
//                 // delete tmp;
//             }
//             else
//                 cur = cur->next;
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 由于nums范围有限
class Solution
{
  public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        bool occ[100000 + 1] = {false};
        for (int i : nums) occ[i] = true;
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while (cur->next)
        {
            int key = cur->next->val;
            if (occ[key])
            {
                // ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                // delete tmp;
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};

// @lc code=end
