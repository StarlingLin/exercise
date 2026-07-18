/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
 */

#include <algorithm>
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

// 134ms
// O(n^2)
// flag记录是否处于某个组件过程，一次遍历，但是find还有O(n)的开销
// class Solution
// {
//   public:
//     int numComponents(ListNode* head, vector<int>& nums)
//     {
//         int ans = 0;
//         bool flag = false; // now in component
//         while (head)
//         {
//             bool inNums = find(nums.begin(), nums.end(), head->val) != nums.end();
//             if (!flag && inNums)
//             {
//                 ++ans;
//                 flag = true;
//             }
//             else if (flag && !inNums)
//                 flag = false;
//             head = head->next;
//         }
//         return ans;
//     }
// };

// 0ms
// 考虑到 0<=nums[i]<=10^4，空间换时间
class Solution
{
  public:
    int numComponents(ListNode* head, vector<int>& nums)
    {
        int ans = 0;
        vector<bool> inNums(1e4, false);
        for (int num : nums) inNums[num] = true;
        bool flag = false; // now in component
        while (head)
        {
            int key = head->val;
            if (!flag && inNums[key])
            {
                ++ans;
                flag = true;
            }
            else if (flag && !inNums[key])
                flag = false;
            head = head->next;
        }
        return ans;
    }
};

// @lc code=end
