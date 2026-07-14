#include <cstdlib>

#define ELEMENT_TYPE int

typedef struct LNode
{
    ELEMENT_TYPE data;
    struct LNode* next;
} LNode, *LinkList;

bool ListInit(LinkList& L)
{
    L = nullptr;
    return true;
}

bool ListEmpty(LinkList& L)
{
    return (L == nullptr);
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
    newNode->next = L;
    L = newNode;
    return true;
}

bool ListPushBack(LinkList& L, ELEMENT_TYPE datax)
{
    LNode* newNode = ListBuyNode(datax);
    if (!L)
        L = newNode;
    else
    {
        LNode* cur = L;
        while (cur->next) cur = cur->next;
        cur->next = newNode;
    }
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
    if (latter == L)
        ListPushFront(L, datax);
    else
    {
        LNode* cur = L;
        while (cur->next != latter) cur = cur->next;
        if (!cur) return false;
        LNode* newNode = ListBuyNode(datax);
        newNode->next = latter;
        cur->next = newNode;
    }
    return true;
}

bool ListPopFront(LinkList& L)
{
    if (!L) return false;
    LinkList tmp = L;
    L = L->next;
    delete tmp;
    return true;
}

bool ListPopBack(LinkList& L)
{
    if (!L) return false;
    if (!(L->next))
    {
        delete L;
        L = nullptr;
    }
    else
    {
        LNode* cur = L;
        while (cur->next->next) cur = cur->next;
        delete cur->next;
        cur->next = nullptr;
    }
    return true;
}

bool ListErase(LinkList& L, LNode* del)
{
    if (!L) return false;
    if (L == del)
        return ListPopFront(L);
    else
    {
        LNode* cur = L;
        while (cur->next && cur->next != del) cur = cur->next;
        if (!(cur->next)) return false;
        cur->next = del->next;
        delete del;
    }
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
    if (!L || !delnext || L == delnext) return false;
    if (L->next == delnext)
        ListPopFront(L);
    else
    {
        LNode* cur = L;
        while (cur->next && cur->next->next != delnext) cur = cur->next;
        if (!(cur->next)) return false;
        delete cur->next;
        cur->next = delnext;
    }
    return true;
}

bool ListEraseVal(LinkList& L, ELEMENT_TYPE datax)
{
    if (!L) return false;
    while (L && L->data == datax) ListPopFront(L);
    LNode* cur = L;
    while (cur && cur->next)
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
    LNode* cur = L;
    while (cur)
    {
        if (cur->data == datax) return cur;
        cur = cur->next;
    }
    return nullptr;
}

LNode* ListFindMidNote(LinkList& L)
{
    LNode *fast = L, *slow = L;
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
    LNode* cur = L;
    while (cur)
    {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

bool ListReverse(LinkList& L)
{
    if (!L || !(L->next)) return false;
    LNode *prev = L, *cur = prev->next, *next = cur->next;
    while (cur)
    {
        cur->next = prev; // 转向
        prev = cur;
        cur = next;
        if (next) next = next->next;
    }
    L->next = nullptr;
    L = prev;
    return true;
}

// 合并
LNode* ListMerge(LinkList L1, LinkList L2)
{
    if (!L1) return L2;
    if (!L2) return L1;
    LinkList tmp = new LNode;
    tmp->next = nullptr;
    LNode* cur = tmp;
    while (L1 && L2)
    {
        if (L1->data <= L2->data)
        {
            cur->next = L1;
            L1 = L1->next;
        }
        else
        {
            cur->next = L2;
            L2 = L2->next;
        }
        cur = cur->next;
    }
    cur->next = L1 ? L1 : L2;
    LinkList ret = tmp->next;
    delete tmp;
    return ret;
}
