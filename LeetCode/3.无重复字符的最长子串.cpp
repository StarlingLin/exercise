/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// @lc code=start

// 27ms
// 滑动窗口粗糙版，外层左指针自增，内层右指针维护窗口，未使用哈希
// class Solution
// {
//   public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int left = 0, right = 1, maxv = 0; // 滑动窗口的左右边界
//         for (; left < s.length(); ++left)
//         {
//             while (right < s.length())
//             {
//                 bool flag = false;
//                 for (char c : s.substr(left, right - left))
//                 {
//                     if (c == s[right])
//                     {
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if (flag) { break; }
//                 ++right;
//             }
//             maxv = max(maxv, right - left);
//         }
//         return maxv;
//     }
// };

// 16ms
// 用哈希表记录字符是否出现过，提出length
// class Solution
// {
//   public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<char> seen;
//         int left = 0, right = -1, maxv = 0, l = s.length();
//         for (; left < l; ++left)
//         {
//             if (left) seen.erase(s[left - 1]);
//             while (right + 1 < l && !seen.count(s[right + 1]))
//             {
//                 seen.insert(s[right + 1]);
//                 ++right;
//             }
//             maxv = max(maxv, right - left + 1);
//         }
//         return maxv;
//     }
// };

// 35ms
// 外层右指针自增，内层左指针
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<char> seen;
//         int maxv = 0, l = s.length();
//         for (int left = 0, right = 0; right < l; ++right)
//         {
//             while (seen.contains(s[right])) seen.erase(s[left++]);
//             seen.insert(s[right]);
//             maxv = max(maxv, right - left + 1);
//         }
//         return maxv;
//     }
// };

// 3ms
// 记录字符上一次出现位置，而不只是是否在窗口出现过
// 由题设字符都是ASCII，可以用一个小vector维护
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         vector<int> lastseen(256, -1);
//         int maxv = 0, left = -1; // left带一点哨兵性质，left+1是窗口第一个元素
//         for (int right = 0; right < s.length(); ++right)
//         {
//             if (lastseen[s[right]] > left) // 右边界读到的字符上次出现在窗口内
//                 left = lastseen[s[right]];
//             lastseen[s[right]] = right;
//             maxv = max(maxv, right - left);
//         }
//         return maxv;
//     }
// };

// 0ms
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> lastseen(256, -1);
        int maxv = 0, left = -1; // left带一点哨兵性质，left+1是窗口第一个元素
        for (int right = 0; right < s.length(); ++right)
        {
            left = max(left, lastseen[s[right]]); // 合并两行一下，少一次调用
            lastseen[s[right]] = right;
            maxv = max(maxv, right - left);
        }
        return maxv;
    }
};

// @lc code=end
