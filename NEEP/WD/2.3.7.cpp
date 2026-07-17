#include <climits>
#include <vector>

#define ElemType int
#define Status int

using namespace std;

typedef struct SList
{
    ElemType data;
    struct SList* next;
} SNode, *SLinkList;

typedef struct DList
{
    ElemType data;
    struct DList* prev;
    struct DList* next;
} DNode, *DLinkList;

typedef struct List13
{
    ElemType data;
    size_t freq;
    struct List13* prev;
    struct List13* next;
} Node13, *LinkList13;

typedef struct List17
{
    ElemType data;
    struct List17* link;
} Node17, *LinkList17;

typedef struct List19
{
    ElemType data;
    struct List19* link;
} Node19, *LinkList19;

typedef struct node
{
    int data;
    struct node* next;
} NODE;

// 01
void delx(SLinkList L, ElemType x)
{
    SNode *prev = L, *cur = L->next;
    while (cur)
    {
        if (cur->data == x)
        {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
}

// 02
void del_min(SLinkList L)
{
    SNode *min = L->next, *prev = L, *prevmin = L;
    while (prev->next)
    {
        if (prev->next->data < min->data)
        {
            min = prev->next;
            prevmin = prev;
        }
        prev = prev->next;
    }
    prevmin->next = min->next;
    delete min;
}

// 03
void reverse_sl(SLinkList L)
{
    if (!L->next || !L->next->next) return;
    SNode *prev = nullptr, *cur = L->next;
    while (cur)
    {
        SNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    L->next = prev;
}

// 04
void del_ran(SLinkList L, ElemType min, ElemType max)
{
    SNode *prev = L, *cur = L->next;
    while (cur)
    {
        if (cur->data < max && cur->data > min)
        {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
}

// 05
SNode* find_com(SLinkList L1, SLinkList L2)
{
    SNode *a = L1->next, *b = L2->next;
    while (a != b)
    {
        a = a ? a->next : L2->next;
        b = b ? b->next : L1->next;
    }
    return a;
}

// 06
void split_sl(SLinkList& L, SLinkList& S1, SLinkList& S2)
{
    S1 = L, S2 = new SNode;
    S2->next = nullptr;
    SNode* curA = S1->next;
    while (curA && curA->next)
    {
        SNode* curB = curA->next;
        curA->next = curB->next; // 把curb从L里摘出来，剩下就是S1了
        curB->next = S2->next;   // curb头插到S2自然就逆序了
        S2->next = curB;
        curA = curA->next; // 后移
    }
}

// 07
void del_repeat(SLinkList L)
{
    SNode* cur = L->next;
    while (cur)
    {
        if (cur->next && cur->data == cur->next->data)
        {
            SNode* tmp = cur->next;
            cur->next = tmp->next;
            delete tmp;
        }
        else
            cur = cur->next;
    }
}

// 08
void merge_com(SLinkList A, SLinkList B, SLinkList& C)
{
    C = new SNode;
    SNode *a = A->next, *b = B->next, *c = C;
    while (a && b)
    {
        if (a->data == b->data)
        {
            c->next = new SNode;
            c->next->data = a->data;
            c = c->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
            a = a->next;
        else
            b = b->next;
    }
    c->next = nullptr;
}

// 09
void merge_com_to_A(SLinkList A, SLinkList B)
{
    SNode *a = A, *b = B->next;
    while (a->next && b)
    {
        if (a->next->data == b->data)
        {
            a = a->next;
            b = b->next;
        }
        else if (a->next->data < b->data)
        {
            SNode* tmp = a->next;
            a->next = tmp->next;
            delete tmp;
        }
        else
            b = b->next;
    }
    while (a->next)
    {
        SNode* tmp = a->next;
        a->next = tmp->next;
        delete tmp;
    }
}

// 10
bool is_sub(SLinkList A, SLinkList B)
{
    SNode *a = A->next, *b = B->next, *flag = a;
    while (a && b)
    {
        if (a->data == b->data)
        {
            a = a->next;
            b = b->next;
        }
        else
        {
            flag = flag->next;
            a = flag, b = B->next;
        }
    }
    if (!b)
        return true;
    else
        return false;
}

// kmp
bool is_sub_kmp(SLinkList A, SLinkList B)
{
    vector<ElemType> pattern; // 把B放到数组里便于随机访问
    for (SNode* cur = B->next; cur; cur = cur->next) pattern.push_back(cur->data);
    int lenb = pattern.size();
    if (!lenb) return true;
    vector<int> lps(lenb, 0); // 构造前缀函数,lps[j-2]+1 = next[j]
    for (int i = 1, j = 0; i < lenb; ++i)
    {
        while (j > 0 && pattern[i] != pattern[j]) j = lps[j - 1];
        if (pattern[i] == pattern[j]) ++j;
        lps[i] = j;
    }
    for (SNode *cur = A->next, int j = 0; cur; cur = cur->next)
    {
        while (j > 0 && cur->data != pattern[j]) j = lps[j - 1];
        if (cur->data == pattern[j]) ++j;
        if (j == lenb) return true;
    }
    return false;
}

// 11
bool is_symmetry_dc(DLinkList L)
{
    DNode *b = L->prev, *f = L->next;
    while (b != f && b->next != f)
    {
        if (b->data == f->data)
        {
            b = b->prev;
            f = f->next;
        }
        else
            return false;
    }
    return true;
}

// 12
SLinkList connect_sc(SLinkList h1, SLinkList h2)
{
    SNode *t1 = h1, *t2 = h2;
    while (t1->next != h1) t1 = t1->next;
    while (t2->next != h2) t2 = t2->next;
    t1->next = h2;
    t2->next = h1;
    return h1;
}

// 13
Node13* Locate(LinkList13 L, ElemType x)
{
    Node13 *loc = L->next, *cmp;
    while (loc && loc->data != x) loc = loc->next;
    if (!loc) return nullptr;
    ++loc->freq;
    cmp = loc;
    while (cmp != L && cmp->freq <= loc->freq) cmp = cmp->prev;
    loc->prev->next = loc->next;
    loc->next->prev = loc->prev;
    loc->next = cmp->next;
    cmp->next = loc;
    loc->next->prev = loc;
    loc->prev = cmp;
    return loc;
}

// 14
void move_k(SLinkList& L, size_t n, size_t k)
{
    SNode* endNew = L;
    for (size_t i = 1; i < n - k; ++i) endNew = endNew->next;
    SNode* end = endNew;
    for (size_t i = n - k; i < n; ++i) end = end->next;
    end->next = L;
    L = endNew->next;
    endNew->next = nullptr;
}

// 15
bool has_cycle(SLinkList L)
{
    SNode *slow = L, *fast = L;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// 16
int max_twinsum(SLinkList L)
{
    int maxsum = INT_MIN;
    SNode *slow = L, *fast = L;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    SLinkList rev = nullptr;
    SNode *tmp = slow, *next;
    while (tmp)
    {
        next = tmp->next;
        tmp->next = rev;
        rev = tmp;
        tmp = next;
    }
    SNode *l = L, *r = rev;
    while (r)
    {
        int sum = l->data + r->data;
        if (sum > maxsum) maxsum = sum;
        l = l->next, r = r->next;
    }
    return maxsum;
}

// 17
Status find_kth_r(LinkList17 list, size_t k, ElemType& data)
{
    if (!list || !k) return 0;
    Node17 *toKr = list, *toEnd = list;
    while (k--)
    {
        toEnd = toEnd->link;
        if (!toEnd) return 0;
    }
    while (toEnd)
    {
        toKr = toKr->link;
        toEnd = toEnd->link;
    }
    data = toKr->data;
    return 1;
}

// 18
SNode* find_com_suffix(SLinkList str1, SLinkList str2)
{
    SNode *p1 = str1->next, *p2 = str2->next;
    while (p1 != p2)
    {
        p1 = p1 ? p1->next : str2->next;
        p2 = p2 ? p2->next : str1->next;
    }
    return p1;
}

// 19
void del_same_abs(LinkList19 head, size_t n)
{
    vector<bool> absocc(n + 1, false);
    Node19 *prev = head, *cur = head->link;
    while (cur)
    {
        size_t curabs = abs(cur->data);
        if (absocc[curabs])
        {
            prev->link = cur->link;
            delete cur;
            cur = prev->link;
        }
        else
        {
            absocc[curabs] = true;
            cur = cur->link;
            prev = prev->link;
        }
    }
}

// 20
void rearrange(NODE* L)
{
    NODE *slow = L, *fast = L->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    NODE *prev = nullptr, *cur = slow->next;
    slow->next = nullptr;
    while (cur)
    {
        NODE* tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    NODE *r = prev, *l = L->next;
    while (r)
    {
        NODE* tmp = r->next;
        r->next = l->next;
        l->next = r;
        r = tmp;
        l = l->next->next;
    }
}