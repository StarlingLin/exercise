/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

#include <string>

using namespace std;

// @lc code=start

// #DRAFT
//
// offset = cycle-2*level
// 1   9    null
// 2  8a    6
// 3 7 b    4
// 46  c    2
// 5   d    null
//
// offset                 level
// null                   0
// cycle-2                1
// cycle-4                2
// cycle-6                3
// cycle-2i               i
//
// DRAFT#

// 0ms
// 直接构造 O(n)
// 这题直接想周期和每一行的偏移就行，用二维数组啥的纯搞笑的
class Solution
{
  public:
    string convert(string s, int numRows)
    {
        if (numRows == 1) return s;
        string ans = "";
        int cycle = 2 * numRows - 2, len = s.length();
        for (int level = 0; level < numRows; ++level)
        {
            for (int i = level; i < len; i += cycle)
            {
                ans += s[i];
                int offset = cycle - 2 * level;
                bool gapRow = level && (numRows - level - 1);
                if (gapRow && (i + offset < len)) ans += s[i + offset];
            }
        }
        return ans;
    }
};
// @lc code=end
