/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start

// 8ms
// 暴力：合并、排序、寻找 O(nlog(n))
// class Solution
// {
//   public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//     {
//         vector<int> merge;
//         for (auto n : nums1) merge.push_back(n); // O(n)
//         for (auto n : nums2) merge.push_back(n);
//         sort(merge.begin(), merge.end()); // O(nlogn)
//         int len = merge.size();
//         return (len % 2) ? merge[len / 2] : (merge[len / 2 - 1] + merge[len / 2]) / 2.0;
//     }
// };

// 0ms
// 双指针模拟归并 O(m+n)
// class Solution
// {
//   public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//     {
//         int len = nums1.size() + nums2.size(), pre = 0, cur = 0;
//         auto it1 = nums1.begin(), it2 = nums2.begin();
//         for (int i = 0; i <= len / 2; ++i)
//         {
//             pre = cur;
//             if (it1 != nums1.end() && (it2 == nums2.end() || *it1 <= *it2))
//                 cur = *it1, ++it1;
//             else
//                 cur = *it2, ++it2;
//         }
//         double ans = (len % 2) ? cur : static_cast<double>(pre + cur) / 2;
//         return ans;
//     }
// };

// 0ms
// 二分淘汰 O(log_2(m+n))
// 实现找数组的第k位可以解决，k初始=len/2-1
// 比较nums1[k/2-1]和nums2[k/2-1]分类讨论
// 谁小，谁的前面部分就可以舍弃，结果一定不在这里
// 剩余的部分再找第k/2位，因为舍弃了k/2个元素
// 以此类推就不停二分直到找到
// class Solution
// {
//   public:
//     int getKth(vector<int>& nums1, vector<int>& nums2, int k, int start1, int start2)
//     {
//         int len1 = nums1.size(), len2 = nums2.size();
//         if (start1 == len1) return nums2[start2 + k - 1];
//         if (start2 == len2) return nums1[start1 + k - 1];
//         if (k == 1) return min(nums1[start1], nums2[start2]);
//         int find1 = min(start1 + k / 2 - 1, len1 - 1);
//         int find2 = min(start2 + k / 2 - 1, len2 - 1);
//         if (nums1[find1] <= nums2[find2])
//             return getKth(nums1, nums2, k - (find1 - start1 + 1), find1 + 1, start2);
//         else
//             return getKth(nums1, nums2, k - (find2 - start2 + 1), start1, find2 + 1);
//     }

//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
//     {
//         int len = nums1.size() + nums2.size();
//         return (len % 2) ? getKth(nums1, nums2, (len + 1) / 2, 0, 0)
//                          : (getKth(nums1, nums2, len / 2, 0, 0) + getKth(nums1, nums2, len / 2 + 1, 0, 0)) / 2.0;
//     }
// };

// 0ms
// 二分划分 O(log_2(min(m, n))) 最优
// 把两个数组的虚拟合并划分成左右两半，左半小于右半，然后通过左最大和右最小算出中位数
// 左半总划分量不变，通过调整nums1（确保nums1更短以达到min）的左划分量逼近正确划分
class Solution
{
  public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int len1 = nums1.size(), len2 = nums2.size(), len = len1 + len2;
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        int llen = (len + 1) / 2; // 左半长度>=右半
        if (!len1) return (len2 % 2) ? nums2[len2 / 2] : (nums2[len2 / 2] + nums2[len2 / 2 - 1]) / 2.0;
        if (!len2) return (len1 % 2) ? nums1[len1 / 2] : (nums1[len1 / 2] + nums1[len1 / 2 - 1]) / 2.0;
        int left = 0, right = len1; // 对nums1左划分量的搜索范围   1run:[0,len1]
        int cut1, cut2;             // 两个数组分别往左边分多少
        int l1, l2, r1, r2;         // 两个数组的左最大和右最小
        do
        {
            cut1 = (left + right) / 2; // 每次排除一半的量  1run:开始检查len1/2
            cut2 = llen - cut1;
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]; // 左划空时不要影响最大值
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r1 = (cut1 >= len1) ? INT_MAX : nums1[cut1]; // 右划空时不要影响最小值
            r2 = (cut2 >= len2) ? INT_MAX : nums2[cut2];
            if (l1 <= r2 && l2 <= r1) // l1肯定小于r1，2同理，所以只要检查交叉即可
                return (len % 2) ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
            else if (l1 > r2)     // 说明nums1左边分多了
                right = cut1 - 1; // 1run:下次搜索范围[0,cut1-1]
            else if (l2 > r1)     // 说明nums1左边分少了
                left = cut1 + 1;  // 1run:下次搜索范围[cut1+1,len1)
        } while (left <= right);
        return 0.0;
    }
};

// @lc code=end
