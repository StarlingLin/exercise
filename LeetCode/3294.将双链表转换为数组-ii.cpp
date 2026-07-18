/*
 * @lc app=leetcode.cn id=3294 lang=cpp
 *
 * [3294] 将双链表转换为数组 II
 */

#include <vector>

using namespace std;

class Node
{
  public:
    int val;
    Node* prev;
    Node* next;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node* prev, Node* next) : val(x), next(next), prev(prev) {}
};

// @lc code=start
/**
 * Definition for doubly-linked list.
 * class Node {
 *     int val;
 *     Node* prev;
 *     Node* next;
 *     Node() : val(0), next(nullptr), prev(nullptr) {}
 *     Node(int x) : val(x), next(nullptr), prev(nullptr) {}
 *     Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
 * };
 */

// 24ms
// class Solution
// {
//   public:
//     vector<int> toArray(Node* node)
//     {
//         Node *prev = node, *next = node->next;
//         vector<int> ans;
//         while (prev)
//         {
//             ans.insert(ans.begin(), prev->val);
//             prev = prev->prev;
//         }
//         while (next)
//         {
//             ans.push_back(next->val);
//             next = next->next;
//         }
//         return ans;
//     }
// };

// 18ms
class Solution
{
  public:
    vector<int> toArray(Node* node)
    {
        vector<int> ans;
        while (node->prev) node = node->prev;
        while (node)
        {
            ans.push_back(node->val);
            node = node->next;
        }
        return ans;
    }
};

// @lc code=end
