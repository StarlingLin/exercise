#define _04

#ifdef _01

#define MaxSize 100
#define ElemType int
typedef struct
{
    ElemType data[MaxSize];
    int front, rear;
    bool tag;
} CQueue;

bool QueueEmpty(const CQueue& Q)
{ return (Q.front == Q.rear && !Q.tag); }

bool QueueFull(const CQueue& Q)
{ return (Q.front == Q.rear && Q.tag); }

bool Enqueue(CQueue& Q, ElemType x)
{
    if (QueueFull(Q)) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    Q.tag = true;
    return true;
}

bool DeQueue(CQueue& Q, ElemType& ret)
{
    if (QueueEmpty(Q)) return false;
    ret = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    Q.tag = false;
    return true;
}

#endif

#ifdef _02

#include <queue>
#include <stack>

using namespace std;

#define ElemType int

void ReverseQueue(stack<ElemType>& S, queue<ElemType>& Q)
{
    ElemType tmp;
    while (!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        S.push(tmp);
    }
    while (!S.empty())
    {
        tmp = S.top();
        S.pop();
        Q.push(tmp);
    }
}

#endif

#ifdef _03

#include <stack>
using namespace std;

#define ElemType int

// 模拟实现题设
void Push(stack<ElemType>& S, ElemType x)
{ S.push(x); }
void Pop(stack<ElemType>& S, ElemType& x)
{
    x = S.top();
    S.pop();
}
bool StackEmpty(const stack<ElemType>& S)
{ return S.empty(); }
bool StackOverflow(const stack<ElemType>& S)
{ return false; }

// 完成题目
bool Enqueue(stack<ElemType>& S1, stack<ElemType>& S2, ElemType x)
{
    if (StackOverflow(S1) && !StackEmpty(S2)) return false;
    if (StackOverflow(S1) && StackEmpty(S2))
        while (!StackEmpty(S1))
        {
            ElemType tmp;
            Pop(S1, tmp);
            Push(S2, tmp);
        }
    Push(S1, x);
    return true;
}

bool Dequeue(stack<ElemType>& S1, stack<ElemType>& S2, ElemType& x)
{
    if (StackEmpty(S1) && StackEmpty(S2)) return false;
    if (StackEmpty(S2) && !StackEmpty(S1))
        while (!StackEmpty(S1))
        {
            ElemType tmp;
            Pop(S1, tmp);
            Push(S2, tmp);
        }
    Pop(S2, x);
    return true;
}

bool QueueEmpty(stack<ElemType>& S1, stack<ElemType>& S2)
{ return StackEmpty(S1) && StackEmpty(S2); }

#endif

#ifdef _04

#endif