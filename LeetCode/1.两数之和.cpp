/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start

// 55ms
// 暴力
// class Solution
// {
//   public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         for (int i = 0; i < nums.size(); ++i)
//             for (int j = i + 1; j < nums.size(); ++j)
//                 if (target == nums[i] + nums[j])
//                     return {i, j};
//         return {};
//     }
// };

// 4ms
// 哈希
// class Solution
// {
//   public:
//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         unordered_map<int, int> hashtbl;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (hashtbl.find(target - nums[i]) != hashtbl.end())
//                 return {hashtbl[target - nums[i]], i};
//             hashtbl[nums[i]] = i;
//         }
//         return {};
//     }
// };

// 0ms
// 提出need，并且减少一次return中的hash遍历
class Solution
{
  public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashtbl;
        for (int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];
            auto it = hashtbl.find(need);
            if (it != hashtbl.end()) return {it->second, i};
            hashtbl[nums[i]] = i;
        }
        return {};
    }
};

// @lc code=end
