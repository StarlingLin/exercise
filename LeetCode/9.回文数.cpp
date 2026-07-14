// @before-stub-for-debug-begin
#include "commoncppproblem9.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

#include <cstdlib>

// @lc code=start

// 3ms
// 反转，溢出判定，比较
// class Solution
// {
//   public:
//     bool isPalindrome(int x)
//     {
//         if (x < 0) return false;
//         int rev = 0, tmp = x;
//         while (tmp)
//         {
//             int digit = tmp % 10;
//             if (rev > (INT_MAX - digit) / 10) return false;
//             rev = rev * 10 + digit;
//             tmp /= 10;
//         }
//         return (rev == x);
//     }
// };

// 0ms
// 只反转一半
class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int rev = 0, tmp = x;
        while (tmp > rev)
        {
            int digit = tmp % 10;
            rev = rev * 10 + digit;
            tmp /= 10;
        }
        return (rev == tmp) || (rev / 10 == tmp);
    }
};

// @lc code=end