/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组是否存在循环
 */

#include <vector>

using namespace std;

// @lc code=start

// 55ms
// 模拟，双指针 O(n^2)
// 注意题目条件：
// 所有 nums[seq[j]] 应当不是 全正 就是 全负
// 也就是说题目要求的环中所有元素都朝一个方向
// class Solution
// {
//   public:
//     bool circularArrayLoop(vector<int>& nums)
//     {
//         int len = nums.size();
//         auto ringCheck = [&](int i) -> bool
//         {
//             bool positive = nums[i] > 0;
//             auto next = [&](int j) -> int
//             {
//                 int nxt = ((j + nums[j]) % len + len) % len;
//                 if (nums[j] > 0 != positive || nums[nxt] > 0 != positive) return -1;
//                 return nxt;
//             };
//             int slow = i, fast = i;
//             while (next(slow) >= 0 && next(fast) >= 0 && next(next(fast)) >= 0)
//             {
//                 slow = next(slow), fast = next(next(fast));
//                 if (slow == fast) return slow != next(slow);
//             }
//             return false;
//         };
//         for (int i = 0; i < len; ++i)
//             if (ringCheck(i)) return true;
//         return false;
//     }
// };

// 0ms
// 数组标记
class Solution
{
  public:
    bool circularArrayLoop(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> vis(len, 0);
        int round = 0;
        auto next = [&](int j) -> int { return ((j + nums[j]) % len + len) % len; };
        for (int i = 0; i < len; ++i)
        {
            if (vis[i]) continue;
            ++round;
            bool positive = nums[i] > 0;
            int cur = i;
            while (!vis[cur] && (nums[cur] > 0) == positive)
            {
                vis[cur] = round;
                cur = next(cur);
            }
            if ((nums[cur] > 0) == positive && vis[cur] == round)
                if (next(cur) != cur) return true;
        }
        return false;
    }
};

// @lc code=end
