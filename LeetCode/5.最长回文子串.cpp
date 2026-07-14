/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <functional>
#include <string>
#include <vector>

using namespace std;

// @lc code=start

// 103ms
// 暴力 O(n^3) 很多时候会在n^2程度因为isPali一般相对小达不到n
// class Solution
// {
//   public:
//     string longestPalindrome(string s)
//     {
//         int len = s.length();
//         string longest = "";
//         for (int i = 0; i < len; ++i)
//             for (int j = i; j < len; ++j)
//                 if (j - i + 1 > longest.length() && isPali(s, i, j)) longest = s.substr(i, j - i + 1);
//         return longest;
//     }

//     bool isPali(const string& s, int i, int j)
//     {
//         while (i < j)
//         {
//             if (s[i] != s[j]) return false;
//             i++, j--;
//         }
//         return true;
//     }
// };

// 122ms
// DP动态规划 O(n^2) 任何情况都是n^2
// dp[i][j]代表i到j的子串是否为回文串
// 因此，s[i]=s[j]的时候，dp[i][j]=dp[i+1][j-1]
// class Solution
// {
//   public:
//     string longestPalindrome(string s)
//     {
//         int len = s.length();
//         if (len <= 1) return s;
//         string longest = s.substr(0, 1);
//         vector<vector<bool>> dp(len, vector<bool>(len));
//         for (int i = 0; i < len; ++i) dp[i][i] = true; // 长度1子串必回文
//         for (int i = len - 1; i >= 0; --i)             // 左边界
//         {
//             for (int j = i + 1; j < len; ++j) // 右边界
//             {
//                 if (s[i] == s[j])
//                 {
//                     if (j - i == 1 || dp[i + 1][j - 1])
//                     {
//                         dp[i][j] = true;
//                         if (j - i + 1 > longest.size()) longest = s.substr(i, j - i + 1);
//                     }
//                 }
//             }
//         }
//         return longest;
//     }
// };

// 4ms
// 中心扩展法 O(n^2) 很多时候会在n程度，因为expand一般相对小达不到n
// 从每个回文中心向两边扩展到回文最大
// 共2n-1个回文中心：n个数和n-1个间隔
// class Solution
// {
//   public:
//     string longestPalindrome(string s)
//     {
//         int len = s.length();
//         if (len <= 1) return s;
//         int l = 0, r = 0;
//         for (int i = 0; i < len; ++i)
//         {
//             int sublen = max(expand(s, i, i), expand(s, i, i + 1));
//             if (sublen > r - l + 1)
//             {
//                 l = i - (sublen - 1) / 2;
//                 r = i + sublen / 2;
//             }
//         }
//         return s.substr(l, r - l + 1);
//     }

//     int expand(const string& s, int l, int r)
//     {
//         while (l >= 0 && r < s.length() && s[l] == s[r]) --l, ++r;
//         return r - l - 1;
//     }
// };

// 3ms
// Manacher算法 O(n)
// 1. 首先通过对原字符串改造来避免奇偶性区别：
// 插入#使串中每个字符都被#包裹，这样进行中心扩展的话，每个回文中心都可以奇串解决
// 可以再头插^尾插$作为哨兵位使用，使abcd变形成^#a#b#c#d#$
// 2. 用ex(n)记录第n个位置的expand长度（见中心扩展法）
// *：这种情况下改造字符串的expand长度正好是原串的回文字符串总长
// 我们会发现，比方说在mid的expand范围内（也就是mid为中心的回文子串smid中）
// 如果l和r关于mid对称（L、R为mid的expand范围的左右边界）
// smid:L----l----mid----r----R
// 对称：l+r = 2mid   臂长：ex(mid) = R-mid
// 那么实际上l、mid、r的expand值就存在一定关系，我们就能先把r的值记录为：
// ex(r) := min(ex(l), R-r)
// ☆注意这里不一定是最终结果，只是以此开始寻找ex(r)的实际值，达到淘汰的目的
// 原因我们可以分类讨论：
// 1)   如果ex(l) < R-r = l-L，那就是l的expand区间完全在mid的expand区间内
//      那么这个结论是看图就很容易说明的，l和r的expand区间完全对称，直接得出
// 2）  如果ex(l) >= R-r， 那说明l的expand区间超过了mid的区间左边界
//      那么由于对称性，r的expand区间右边也会超过R，我们先记录为ex(r)=R-r
// 随后我们再此基础上用中心扩展法即可。
// 和中心扩展的实际区别就是每次扩展不在从臂长0开始，预先由对称关系舍弃一部分。
class Solution
{
  public:
    string longestPalindrome(string s)
    {
        if (s.length() < 2) return s;
        string edited = "^";
        for (char ch : s) (edited += '#') += ch;
        edited += "#$";
        int editedLen = edited.length();
        vector<int> ex(editedLen, 0);
        int mid = 0, R = 0;
        int ansmid = 0, ansLen = 0;
        for (int r = 1; r < editedLen - 1; ++r) // 考虑哨兵位
        {
            if (r < R) // 如果r在目前维护的mid区间内
            {
                int l = 2 * mid - r;       // 由lr对称得到l
                ex[r] = min(ex[l], R - r); // 那就进行ex[r]的预填写
            }
            // 接着开始中心扩展
            while (edited[r + ex[r] + 1] == edited[r - ex[r] - 1]) ++ex[r];
            // r的区间作为可用的右边界更靠后的对称区间，更新mid、R
            if (r + ex[r] > R)
            {
                mid = r;
                R = r + ex[r];
            }
            if (ex[r] > ansLen) // 记录最大值
            {
                ansmid = r;
                ansLen = ex[r];
            }
        }
        int ansL = (ansmid - ansLen) / 2;
        return s.substr(ansL, ansLen);
    }
};

// 15ms
// 字符串哈希+双指针 O(n) 整理自Author:subcrip
// 对字符串s[n-1]有回文子串最大长度k，那么s[n]的回文子串最大长度<=k+2
// 那么维护左指针l表示上次最长回文子串的左位置，然后判断s[l-1...i]是不是新回文子串
// 如果是则更新答案，如果不是就l右移一位后继续判断直到形成回文子串
// 最终得到的就是最长的回文子串。这里外层复杂度为O(n)，内层为回文子串的判定。
// 使用字符串哈希来将回文子串的判定复杂度降到O(1)
// class Solution
// {
//   public:
//     string longestPalindrome(string s)
//     {
//         long long base1 = 825;
//         long long base2 = 87825;
//         long long prime = 1e9 + 7;
//         int len = s.length();
//         // 预处理base的幂次，p[i]为base的i次幂，双哈希降低碰撞
//         vector<long long> p1(len + 1), p2(len + 1);
//         long long hash1 = 0, hash2 = 0;
//         p1[0] = p2[0] = 1;
//         for (int i = 1; i < len; ++i)
//         {
//             p1[i] = (p1[i - 1] * base1) % prime;
//             p2[i] = (p2[i - 1] * base2) % prime;
//         }
//         // pa[i] = hash(s[0...i-1])正向前缀哈希
//         // 那么hash(s[l...r]) = mod( pa[r+1] - pa[l]*p[r-l+1] , prime )
//         vector<long long> pa1(len + 1), pa2(len + 1);
//         hash1 = hash2 = 0;
//         for (int i = 1; i <= len; ++i)
//         {
//             hash1 = (hash1 * base1 + s[i - 1]) % prime;
//             hash2 = (hash2 * base2 + s[i - 1]) % prime;
//             pa1[i] = hash1;
//             pa2[i] = hash2;
//         }
//         // sa[i] = hash(s[len-1...i])反向后缀哈希
//         // 那么hash(s[r...l]) = mod( sa[l] - sa[r+1]*p[r-l+1] , prime )
//         vector<long long> sa1(len + 1), sa2(len + 1);
//         hash1 = hash2 = 0;
//         for (int i = len - 1; i >= 0; --i)
//         {
//             hash1 = (hash1 * base1 + s[i]) % prime;
//             hash2 = (hash2 * base2 + s[i]) % prime;
//             sa1[i] = hash1;
//             sa2[i] = hash2;
//         }
//         function<long long(long long, long long)> mod = [&](long long value, long long prime)
//         { return (value % prime + prime) % prime; };
//         // 回文判断,s[l...p]和s[r...q]是否相同，lambda表达式
//         function<bool(int, int)> isPali = [&](int l, int r)
//         {
//             int p = (l + r) >> 1, q = (l + r + 1) >> 1;
//             return mod((pa1[p + 1] - pa1[l] * p1[p - l + 1]), prime) ==
//                        mod((sa1[q] - sa1[r + 1] * p1[r + 1 - q]), prime) &&
//                    mod((pa2[p + 1] - pa2[l] * p2[p + 1 - l]), prime) ==
//                        mod((sa2[q] - sa2[r + 1] * p2[r + 1 - q]), prime);
//         };
//         // 主体逻辑
//         pair<int, int> ans;
//         for (int l = 0, r = 0; r < len; ++r)
//         {
//             l = max(0, l - 1);
//             while (!isPali(l, r)) ++l;
//             ans = max(ans, {r - l + 1, l});
//         }
//         return s.substr(ans.second, ans.first);
//     }
// };

// @lc code=end
