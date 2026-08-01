/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include <vector>

using namespace std;

// @lc code=start

// 当然可以两层循环暴力解

// 0ms
// 和457题很像，建图（内向基环树），快慢指针，判环
// class Solution
// {
//   public:
//     int findDuplicate(vector<int>& nums)
//     {
//         int slow = 0, fast = 0;
//         do
//         {
//             slow = nums[slow];
//             fast = nums[nums[fast]];
//         } while (slow != fast);
//         slow = 0;
//         while (slow != fast)
//         {
//             slow = nums[slow];
//             fast = nums[fast];
//         }
//         return slow;
//     }
// };

// 39ms
// 官方题解的位运算方法
class Solution
{
  public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size(), ans = 0, binlen = 1;
        // binlen = n ? 32 - __lzcnt(n) : 1;    //32减左零数
        int tmp = n - 1;
        while (tmp >>= 1) ++binlen; // 取n二进制位数
        for (int digit = 0; digit <= binlen; ++digit)
        {
            int zeroNums = 0, zeroSum = 0;
            for (int i = 0; i < n; ++i)
            {
                if (nums[i] & (1 << digit)) ++zeroNums;
                if (i >= 1 && (i & (1 << digit))) ++zeroSum;
            }
            if (zeroNums > zeroSum) ans |= 1 << digit; // 第digit位置1
        };
        return ans;
    }
};

// @lc code=end
