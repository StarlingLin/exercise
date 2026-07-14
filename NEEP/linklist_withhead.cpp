#include <cstdlib>

#define ELEMENT_TYPE int

typedef struct LNode
{
    ELEMENT_TYPE data;
    struct LNode* next;
} LNode, *LinkList;

bool ListInit(LinkList& L)
{
    L = new LNode;
    L->next = nullptr;
    return true;
}

bool ListEmpty(LinkList& L)
{
    return (L->next == nullptr);
}

LNode* ListBuyNode(ELEMENT_TYPE datax)
{
    LNode* newNode = new LNode;
    if (!newNode) exit(EXIT_FAILURE);
    newNode->data = datax;
    newNode->next = nullptr;
    return newNode;
}

bool ListPushFront(LinkList& L, ELEMENT_TYPE datax)
{
    LNode* newNode = ListBuyNode(datax);
    newNode->next = L->next;
    L->next = newNode;
    return true;
}

bool ListPushBack(LinkList& L, ELEMENT_TYPE datax)
{
    LNode* newNode = ListBuyNode(datax);
    LNode* cur = L;
    while (cur->next) cur = cur->next;
    cur->next = newNode;
    return true;
}

bool ListInsertAfter(LNode* former, ELEMENT_TYPE datax)
{
    LNode* newNode = ListBuyNode(datax);
    newNode->next = former->next;
    former->next = newNode;
    return true;
}

bool ListInsertBefore(LinkList& L, LNode* latter, ELEMENT_TYPE datax)
{
    if (!L || !latter) return false;
    LNode* cur = L;
    while (cur && cur->next != latter) cur = cur->next;
    if (!cur) return false;
    LNode* newNode = ListBuyNode(datax);
    newNode->next = latter;
    cur->next = newNode;
    return true;
}

bool ListPopFront(LinkList& L)
{
    if (!L || !(L->next)) return false;
    LinkList tmp = L->next;
    L->next = tmp->next;
    delete tmp;
    return true;
}

bool ListPopBack(LinkList& L)
{
    if (!L || !(L->next)) return false;
    LNode* cur = L;
    while (cur->next->next) cur = cur->next;
    delete cur->next;
    cur->next = nullptr;
    return true;
}

bool ListErase(LinkList& L, LNode* del)
{
    if (!L || !del) return false;
    LNode* cur = L;
    while (cur && cur->next != del) cur = cur->next;
    if (!cur) return false;
    cur->next = del->next;
    delete del;
    return true;
}

bool ListEraseAfter(LNode* delprev)
{
    if (!delprev || !(delprev->next)) return false;
    LNode* delnext = delprev->next->next;
    delete delprev->next;
    delprev->next = delnext;
    return true;
}

bool ListEraseBefore(LinkList& L, LNode* delnext)
{
    if (!L || !delnext || L == delnext || L->next == delnext) return false;
    LNode* cur = L;
    while (cur->next && cur->next->next != delnext) cur = cur->next;
    if (!(cur->next)) return false;
    delete cur->next;
    cur->next = delnext;
    return true;
}

bool ListEraseVal(LinkList& L, ELEMENT_TYPE datax)
{
    if (!L) return false;
    LNode* cur = L;
    while (cur->next)
    {
        if (cur->next->data == datax)
            ListEraseAfter(cur);
        else
            cur = cur->next;
    }
    return true;
}

LNode* ListFind(LinkList& L, ELEMENT_TYPE datax)
{
    if (!L) return nullptr;
    LNode* cur = L->next;
    while (cur)
    {
        if (cur->data == datax) return cur;
        cur = cur->next;
    }
    return nullptr;
}

LNode* ListFindMidNote(LinkList& L)
{
    LNode *fast = L->next, *slow = L->next;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int ListSize(LinkList& L)
{
    int cnt = 0;
    LNode* cur = L->next;
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

bool ListReverse(LinkList& L)
{
    if (!L || !(L->next) || !(L->next->next)) return false;
    LNode *prev = nullptr, *cur = L->next;
    while (cur)
    {
        LNode* next = cur->next; // 记录一下
        cur->next = prev;        // 反转
        prev = cur;
        cur = next; // 通过记录去下一个节点
    }
    L->next = prev;
    return true;
}

// 合并
LNode* ListMerge(LinkList& L1, LinkList& L2)
{
    if (!L1) return L2;
    if (!L2) return L1;
    LNode *cur1 = L1->next, *cur2 = L2->next, *cur = L1;
    while (cur1 && cur2)
    {
        if (cur1->data <= cur2->data)
        {
            cur->next = cur1;
            cur1 = cur1->next;
        }
        else
        {
            cur->next = cur2;
            cur2 = cur2->next;
        }
        cur = cur->next;
    }
    cur->next = cur1 ? cur1 : cur2;
    delete L2;
    L2 = nullptr;
    return L1;
}
