#include <iostream>
#include <string>

using namespace std;

#define MaxSize 100

typedef struct
{
    char data[MaxSize];
    int top;
} SeqStack;

void InitStack(SeqStack& S)
{ S.top = -1; }

bool StackEmpty(SeqStack& S)
{ return S.top == -1; }

bool StackPush(SeqStack& S, char x)
{
    if (S.top == MaxSize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

bool StackPop(SeqStack& S, char& x)
{
    if (StackEmpty(S)) return false;
    x = S.data[S.top--];
    return true;
}

bool bracketCheck(string s)
{
    SeqStack S;
    InitStack(S);
    for (char ch : s)
    {
        if (ch == '(' || ch == '[' || ch == '{')
            StackPush(S, ch);
        else if (StackEmpty(S))
            return false;
        else
        {
            char topElem;
            StackPop(S, topElem);
            if (ch == '(' && topElem != ')') return false;
            if (ch == '[' && topElem != ']') return false;
            if (ch == '{' && topElem != '}') return false;
        }
    }
    return StackEmpty(S);
}

int main()
{
    string s;
    cout << "请输入括号串: ";
    cin >> s;
    cout << (bracketCheck(s) ? "匹配成功" : "匹配失败") << endl;
    return 0;
}
