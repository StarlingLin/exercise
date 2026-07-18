/*
 * @lc app=leetcode.cn id=3263 lang=cpp
 *
 * [3263] 将双链表转换为数组 I
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

// 0ms
class Solution
{
  public:
    vector<int> toArray(Node* head)
    {
        vector<int> ans;
        while (head)
        {
            ans.push_back(head->val);
            head = head->next;
        }
        return ans;
    }
};
// @lc code=end
