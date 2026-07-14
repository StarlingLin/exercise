/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <string>
using namespace std;

// @lc code=start

// 0ms
// O(n)
class Solution
{
  public:
    int myAtoi(string s)
    {
        int len = s.length(), ans = 0, i = 0;
        bool positive = true;
        while (i < len && s[i] == ' ') ++i;
        if (i < len)
        {
            if (s[i] == '+')
                ++i;
            else if (s[i] == '-')
            {
                positive = false;
                ++i;
            }
        }
        while (i < len && s[i] == '0') ++i;
        while (i < len && isdigit(s[i]))
        {

            int digit = s[i++] - '0';
            // 会发现这两行中对越界的判定结果等价，INT_MIN直接当做越界返回是一样的
            // if (positive && ans > (INT_MAX - digit) / 10) return INT_MAX;
            // if (!positive && -1 * ans < (INT_MIN + digit + 1) / 10) return INT_MIN;
            if (ans > (INT_MAX - digit) / 10) return positive ? INT_MAX : INT_MIN;
            ans = ans * 10 + digit;
        }
        return (positive ? 1 : -1) * ans;
    }
};
// @lc code=end
