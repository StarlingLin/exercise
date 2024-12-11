#define _CRT_SECURE_NOWARNINGS

#include <iostream>

using namespace std;

enum OP
{
    INS = 0,
    DEL = 1
};

struct SListNode
{
    int data;
    SListNode* next;
};

SListNode* CreateSList(int n)
{
    SListNode* head = new SListNode;
    head->next = nullptr;
    SListNode* p = head;

    for (int i = 0; i < n; i++)
    {
        SListNode* node = new SListNode;
        cin >> node->data;
        node->next = nullptr;
        p->next = node;
        p = node;
    }

    return head;
}

void InsSList(SListNode* head, int k, int d)
{
    if (k < 0)
    {
        return;
    }

    SListNode* p = head;

    for (int i = 0; i < k; i++)
    {
        if (p->next == nullptr)
        {
            return;
        }
        p = p->next;
    }

    SListNode* node = new SListNode;
    node->data = d;
    node->next = p->next;
    p->next = node;
}

void DelSList(SListNode* head, int k)
{
    if (k <= 0)
    {
        return;
    }

    SListNode* p = head;

    for (int i = 0; i < k - 1; i++)
    {
        if (p->next == nullptr)
        {
            return;
        }
        p = p->next;
    }

    SListNode* q = p->next;

    if (q != nullptr)
    {
        p->next = q->next;
        delete q;
    }
}

void Print(SListNode* head)
{
    SListNode* p = head->next;

    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }

    cout << endl;
}

int main()
{
    int n, m;
    cin >> n;
    SListNode* head = CreateSList(n);
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int op;
        cin >> op;

        if (op == INS)
        {
            int k, d;
            cin >> k >> d;
            InsSList(head, k, d);
        }
        else if (op == DEL)
        {
            int k;
            cin >> k;
            DelSList(head, k);
        }
    }
    Print(head);

    return 0;
}
