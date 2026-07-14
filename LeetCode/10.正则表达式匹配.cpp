// @before-stub-for-debug-begin
#include "commoncppproblem10.h"
#include <functional>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// #DRAFT
//
// dp[i][j] := s[i-1] match p[j-1] 也就是s前i匹配p前j
// dp[0][0] : "" match "" -> true
//
// if p[j-1] == '*' dp[i][j] need:
//      dp[i][j-2]  只要p前j-2项匹配即可，反正可以当第j-1项匹配零个
//      dp[i-1][j] && s[i-1] == p[j-2]  s多读p的第j-1项是符合匹配的
//      dp[i-1][j] && p[j-2] == '.'   和上情况相似，多读任意字符符合匹配
// if p[j-1] != '*' dp[i][j] need:  正常字符匹配即可
//      dp[i-1][j-1] && s[i-1] == p[j-1]
//      dp[i-1][j-1] && p[j-2] == '.'
//
// Init: dp[0][0] = 1, other =0,
//      Then init 1st row: 如果p的前偶数j位都能保持*，那dp[0][j]为真
//      （也就是偶数位与其两位前保持一致）
//
// DRAFT#

// 0ms
// 动态分配 O(mn)
// class Solution
// {
//   public:
//     bool isMatch(string s, string p)
//     {
//         int lenS = s.length() + 1, lenP = p.length() + 1;
//         vector<vector<bool>> dp(lenS, vector<bool>(lenP, false));
//         dp[0][0] = true;
//         for (int j = 2; j < lenP; j += 2) dp[0][j] = (dp[0][j - 2] && '*' == p[j - 1]);
//         for (int i = 1; i < lenS; ++i)
//         {
//             for (int j = 1; j < lenP; ++j)
//             {
//                 dp[i][j] = (p[j - 1] == '*')
//                                ? dp[i][j - 2] || (dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
//                                : dp[i - 1][j - 1] && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
//             }
//         }
//         return dp[lenS - 1][lenP - 1];
//     }
// };

// 观察到dp每一行的推导只用得到上一行（左边上面和左上）
// 那么实际上不需要建二维数组，一维就够了，空间从O(mn)优化为O(n)
class Solution
{
  public:
    bool isMatch(string s, string p)
    {
        int lenS = s.length() + 1, lenP = p.length() + 1;
        vector<bool> dp(lenP, false);
        dp[0] = true;
        for (int j = 2; j < lenP; j += 2) dp[j] = (dp[j - 2] && '*' == p[j - 1]);
        for (int i = 1; i < lenS; ++i)
        {
            bool pre = dp[0];
            dp[0] = false;
            for (int j = 1; j < lenP; ++j)
            {
                bool tmp = dp[j];
                dp[j] = (p[j - 1] == '*') ? dp[j - 2] || (dp[j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                                          : pre && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
                pre = tmp;
            }
        }
        return dp[lenP - 1];
    }
};

// 0ms
// 记忆化搜索，和上一个的求解方向相反 O(mn)
// dfs(i, j) := s[i...] match p[j...]
// class Solution
// {
//   public:
//     bool isMatch(string s, string p)
//     {
//         int lenS = s.length(), lenP = p.length();
//         vector<vector<bool>> visited(lenS + 1, vector<bool>(lenP + 1, false));
//         // 递归lambda的写法，this auto&&指向自己。C++23的新方法。
//         auto dfs = [&](this auto&& dfs, int i, int j) -> bool
//         {
//             if (j == lenP) return i == lenS;
//             if (visited[i][j]) return false;
//             visited[i][j] = true;
//             // 当前字符能否匹配: s没用完，而且p[j]符合
//             bool matching = (i < lenS) && (p[j] == '.' || p[j] == s[i]);
//             if (j + 1 < lenP && p[j + 1] == '*')     // p[j]*放一起看
//                 return dfs(i, j + 2)                 // 匹配零个
//                        || matching && dfs(i + 1, j); // 匹配一个再转交给下一层
//             return matching && dfs(i + 1, j + 1);
//         };
//         return dfs(0, 0);
//     }
// };

// @lc code=end
