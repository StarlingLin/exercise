// Created on iPad.

#include <functional>
#include <iostream>
#include <unordered_set>
#include <vector>

#define ElemType int

using namespace std;

struct SeqList
{
    int* data;
    int length;
    int maxSize;
};

// 01
bool del_min(SeqList& L, ElemType& val)
{
    int len = L.length, pos = 0;
    if (!len) return false;
    val = L.data[0];
    for (int i = 0; i < len; ++i)
    {
        if (L.data[i] < val)
        {
            val = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[len];
    --L.length;
    return true;
}

// 02
bool rev_seq(SeqList& L)
{
    int len = L.length, left = 0, right = len - 1;
    while (left < right)
    {
        ElemType tmp = L.data[left];
        L.data[left] = L.data[right];
        L.data[right] = tmp;
        ++left, --right;
    }
    return true;
}

// 03
bool del_x(SeqList& L, ElemType val)
{
    int del = 0;
    for (int i = 0; i < L.length; ++i)
    {
        if (L.data[i] == val)
            ++del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// 04
bool del_range(SeqList& L, ElemType s, ElemType t)
{
    if (!L.length || s >= t) return false;
    int del = 0;
    for (int i = 0; i < L.length; ++i)
    {
        if (s <= L.data[i] && L.data[i] <= t)
            ++del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// 05
bool del_same(SeqList& L)
{
    int del = 0;
    for (int i = 1; i < L.length; ++i)
    {
        if (L.data[i - del - 1] == L.data[i])
            ++del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// if unordered
bool del_same(SeqList& L)
{
    unordered_set<ElemType> hash;
    int del = 0;
    for (int i = 0; i < L.length; ++i)
    {
        if (hash.find(L.data[i]) != hash.end())
            ++del;
        else
        {
            hash.insert(L.data[i]);
            L.data[i - del] = L.data[i];
        }
    }
    L.length = L.length - del;
}

// 06
bool merge(SeqList& La, SeqList& Lb, SeqList& Lm)
{
    int lenA = La.length, lenB = Lb.length, size = Lm.maxSize;
    if (lenA + lenB > size) return false;
    int a = 0, b = 0, m = 0;
    while (a < lenA && b < lenB) { Lm.data[m++] = (La.data[a] <= Lb.data[b]) ? La.data[a++] : Lb.data[b++]; }
    while (a < lenA) Lm.data[m++] = La.data[a++];
    while (b < lenB) Lm.data[m++] = Lb.data[b++];
    Lm.length = m;
    return true;
}

// 07
void reverse(ElemType arr[], int l, int r)
{
    while (l < r)
    {
        ElemType tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        ++l, --r;
    }
}
bool exchange(ElemType arr[], int m, int n, int len)
{
    if (m < 0 || n < 0 || m + n > len) return false;
    reverse(arr, 0, m + n - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, m + n - 1);
    return true;
}

// 08
bool searchI(SeqList& L, ElemType x)
{
    int len = L.length;
    bool found = true;
    auto bin_search = [&](this auto&& bin_search, int l, int r) -> int
    {
        if (l > r)
        {
            found = false;
            return l;
        }
        int mid = (l + r) / 2;
        if (L.data[mid] == x) return mid;
        if (L.data[mid] < x)
            return bin_search(mid + 1, r);
        else
            return bin_search(l, mid - 1);
    };
    int ret = bin_search(0, len - 1);
    if (found && ret < len - 1)
    {
        ElemType tmp = L.data[ret];
        L.data[ret] = L.data[ret + 1];
        L.data[ret + 1] = tmp;
    }
    else if (!found)
    {
        for (int i = len; i > ret; --i) L.data[i] = L.data[i - 1];
        L.data[ret] = x;
        ++L.length;
    }
    return true;
}

// no lambda
bool searchI(SeqList& L, ElemType x)
{
    int len = L.length, l = 0, r = len - 1, pos = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (L.data[mid] == x)
        {
            pos = mid;
            break;
        }
        else if (L.data[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (pos != -1 && pos < len - 1)
    {
        ElemType tmp = L.data[pos];
        L.data[pos] = L.data[pos + 1];
        L.data[pos + 1] = tmp;
    }
    else if (pos == -1)
    {
        for (int i = len; i > l; --i) L.data[i] = L.data[i - 1];
        L.data[l] = x;
        ++L.length;
    }
    return true;
}

// 09
void elem_in_all(int A[], int B[], int C[], int n)
{
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n)
    {
        if (A[i] == B[j] && A[i] == C[k])
        {
            cout << A[i] << endl;
            ++i, ++j, ++k;
        }
        else if (A[i] < B[j])
            ++i;
        else if (B[j] < C[k])
            ++j;
        else
            ++k;
    }
}

// 10
void reverseR(int R[], int l, int r)
{
    while (l < r)
    {
        swap(R[l], R[r]);
        ++l, --r;
    }
}
void moveL(int R[], int n, int p)
{
    reverseR(R, 0, n - 1);
    reverseR(R, 0, n - p - 1);
    reverseR(R, n - p, n - 1);
}

// 11
int findMid(int A[], int B[], int n)
{
    int a = 0, b = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (A[a] < B[b])
            ++a;
        else
            ++b;
    }
    return min(A[a], B[b]);
}

// 二分
int findMidBin(int A[], int B[], int n)
{
    int la, ra, ma, lb, rb, mb;
    la = lb = 0, ra = rb = n - 1;
    while (la < ra)
    {
        ma = (la + ra) / 2;
        mb = (lb + rb) / 2;
        int len = ra - la + 1;
        if (A[ma] == B[mb]) return A[ma];
        if (A[ma] < B[mb])
        {
            la = (len % 2) ? ma : ma + 1;
            rb = mb;
        }
        else
        {
            ra = ma;
            lb = (len % 2) ? mb : mb + 1;
        }
    }
    return min(A[la], B[lb]);
}

// 12
int findMain(int A[], int n)
{
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i)
    {
        ++cnt[A[i]];
        if (cnt[A[i]] > n / 2) return A[i];
    }
    return -1;
}

// 摩尔投票法
int findMain(int A[], int n)
{
    int candidate = 0, cnt = 0;
    for (int i = 1; i < n; ++i)
    {
        if (!cnt) candidate = A[i];
        cnt += (A[i] == candidate) ? 1 : -1;
    }
    for (int i = cnt = 0; i < n; ++i)
        if (A[i] == candidate) ++cnt;
    return (cnt > n / 2) ? candidate : -1;
}

// 13
int notOccMinInt(int arr[], int n)
{
    vector<bool> occ(n + 1, false);
    for (int i = 0; i < n; ++i)
        if (arr[i] > 0 && arr[i] <= n + 1) occ[arr[i]] = true;
    for (int i = 1; i <= n; ++i)
        if (occ[i] == false) return i;
    return n + 1;
}

// 14
int distance(int a, int b, int c)
{ return abs(a - b) + abs(a - c) + abs(b - c); }

int minDistance(int A[], int B[], int C[], int lena, int lenb, int lenc)
{
    int mindis = INT_MAX, a = 0, b = 0, c = 0;
    while (a < lena && b < lenb && c < lenc)
    {
        int nowdis = distance(A[a], B[b], C[c]);
        if (nowdis < mindis) mindis = nowdis;
        if (A[a] <= B[b] && A[a] <= C[c])
            ++a;
        else if (B[b] <= A[a] && B[b] <= C[c])
            ++b;
        else
            ++c;
    }
    return mindis;
}