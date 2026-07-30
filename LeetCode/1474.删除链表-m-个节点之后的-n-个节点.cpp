/*
 * @lc app=leetcode.cn id=1474 lang=cpp
 *
 * [1474] 删除链表 M 个节点之后的 N 个节点
 */

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 0ms
// 模拟就行很简单
// class Solution
// {
//   public:
//     ListNode* deleteNodes(ListNode* head, int m, int n)
//     {
//         ListNode dummy(0, head);
//         ListNode* cur = &dummy;
//         while (cur)
//         {
//             for (int i = 0; i < m && cur; ++i) cur = cur->next;
//             for (int j = 0; j < n && cur; ++j)
//             {
//                 // ListNode* tmp = cur->next;
//                 if (cur->next) cur->next = cur->next->next;
//                 // delete tmp;
//             }
//         }
//         return dummy.next;
//     }
// };

// 0ms
// 改双指针省一点点时间
class Solution
{
  public:
    ListNode* deleteNodes(ListNode* head, int m, int n)
    {
        ListNode dummy(0, head);
        ListNode *cur = &dummy, *nxt = cur;
        while (cur)
        {
            for (int i = 0; i < m && cur; ++i) cur = cur->next;
            nxt = cur;
            if (!cur) break;
            for (int j = 0; j < n && nxt; ++j) nxt = nxt->next;
            if (nxt)
            {
                cur->next = nxt->next;
                cur = nxt;
            }
            else
                cur->next = nullptr;
        }
        return dummy.next;
    }
};

// @lc code=end
