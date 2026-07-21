#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define _05

#ifdef _03

bool validIO(string s)
{
    int top = 0;
    for (char ch : s)
    {
        switch (ch)
        {
        case 'I':
            ++top;
            break;
        case 'O':
            --top;
            if (top < 0) return false;
            break;
        }
    }
    if (top) return false;
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << (validIO(s) ? "合法序列" : "非法序列") << endl;
}

#endif

#ifdef _04

typedef struct ListNode
{
    char val;
    ListNode* next;
} LNode, *LinkList;

bool isPali(LinkList L, int n)
{
    int top = 0;
    char* stack = new char[n / 2];
    LNode* cur = L->next;
    while (top < n / 2)
    {
        stack[top] = cur->val;
        cur = cur->next;
        ++top;
    }
    if (n % 2) cur = cur->next;
    while (cur && stack[--top] == cur->val)
    {
        cur = cur->next;
        if (!top)
        {
            delete[] stack;
            return true;
        }
    }
    delete[] stack;
    return false;
}

#endif

#ifdef _05

#define MaxSize 100

typedef struct
{
    int stack[MaxSize];
    pair<int, int> top;
} ShareStack;

bool StackPush(ShareStack& st, int which, int x)
{
    if (which < 0 || which > 1) return false;
    if (st.top.second - st.top.first == 1) return false;
    switch (which)
    {
    case 0:
        st.stack[++st.top.first] = x;
        return true;
    case 1:
        st.stack[--st.top.second] = x;
        return true;
    }
}

bool StackPop(ShareStack& st, int which, int& ret)
{
    if (which < 0 || which > 1) return false;
    switch (which)
    {
    case 0:
        if (st.top.first == -1)
            return false;
        else
        {
            ret = st.stack[st.top.first--];
            return true;
        }
    case 1:
        if (st.top.second == MaxSize)
            return false;
        else
        {
            ret = st.stack[st.top.second++];
            return true;
        }
    }
}

#endif