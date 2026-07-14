// @before-stub-for-debug-begin
#include "commoncppproblem7.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

#include <string>

using namespace std;

// @lc code=start

// 3ms
// 直接调用库函数转字符串处理，可能不符合题意 O(log(x))
// class Solution
// {
//   public:
//     int reverse(int x)
//     {
//         string s = to_string(x); // O(log(x))
//         int l = 0, r = s.length() - 1;
//         if (s[0] == '-') ++l;
//         while (l < r)
//         {
//             swap(s[l], s[r]);
//             ++l, --r;
//         }
//         char* endptr;
//         long long check = strtoll(s.c_str(), &endptr, 10); // O(n) = O(log(x))
//         if (!(INT_MIN < check && check < INT_MAX)) return 0;
//         return static_cast<int>(check);
//     }
// };

// 0ms
// O(log(x))
// 反转的逻辑很简单，边界判定这边，在逐位反转的过程中：
// 如果已经大于INT_MAX/10但还要接受下一位，那说明再接受下一位反转肯定是溢出了，没意义
// 严格来说还要判定正好等于INT_MAX/10，但是这时如果溢出，说明：
// 反转前的原数字首位>7长度还和INT_MAX一样，没有这种情况，INT_MAX是2打头
// 负数同理
class Solution
{
  public:
    int reverse(int x)
    {
        int ans = 0;
        for (int i = x; i != 0; i /= 10)
        {
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
                return 0;
            else
                ans = ans * 10 + i % 10;
        }
        return ans;
    }
};

// @lc code=end
