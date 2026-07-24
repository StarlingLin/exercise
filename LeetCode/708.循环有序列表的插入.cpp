/*
 * @lc app=leetcode.cn id=708 lang=cpp
 *
 * [708] 循环有序列表的插入
 */

class Node
{
  public:
    int val;
    Node* next;

    Node() {}

    Node(int _val)
    {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next)
    {
        val = _val;
        next = _next;
    }
};

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

// 4ms
class Solution
{
  public:
    Node* insert(Node* head, int insertVal)
    {
        if (!head)
        {
            Node* ret = new Node(insertVal);
            ret->next = ret;
            return ret;
        }
        Node* cur = head->next;
        while (cur != head)
        {
            int cval = cur->val, nval = cur->next->val;
            if (cval <= insertVal && insertVal <= nval) break;
            if (cval > nval && (insertVal > cval || insertVal < nval)) break;
            cur = cur->next;
        }
        Node* ins = new Node(insertVal, cur->next);
        cur->next = ins;
        return head;
    }
};
// @lc code=end
