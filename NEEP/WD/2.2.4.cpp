// Created on iPad.
#include <functional>

// 01
bool del_min(SeqList& L, ElemType& val) {
    int len = L.length, pos = 0;
    if (!len) return false;
    val = L.data[0];
    for (int i = 0; i < len; ++i) {
        if (L.data[i] < val) {
            val = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[len];
    --L.length;
    return true;
}

// 02
bool rev_seq(SeqList& L) {
    int len = L.length, left = 0, right = len - 1;
    while (left < right) {
        ElemType tmp = L.data[left];
        L.data[left] = L.data[right];
        L.data[right] = tmp;
        ++left, --right;
    }
    return true;
}

// 03
bool del_x(SeqList& L, ElemType val) {
    int del = 0;
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == val) ++ del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// 04
bool del_range(SeqList& L, ElemType s, ElemType t) {
    if (!L.length || s >= t) return false;
    int del = 0;
    for (int i = 0; i < L.length; ++i) {
        if (s <= L.data[i] && L.data[i] <= t) ++del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// 05
bool del_same(SeqList& L) {
    int del = 0;
    for (int i = 1; i < L.length; ++i) {
        if (L.data[i - del - 1] == L.data[i]) ++ del;
        else
            L.data[i - del] = L.data[i];
    }
    L.length = L.length - del;
    return true;
}

// if unordered
bool del_same(SeqList& L) {
    unordered_set<ElemType> hash;
    int del = 0;
    for (int i = 0; i < L.length; ++i) {
        if (hash.find(L.data[i] != hash.end())) ++del;
        else {
            hash.insert(L.data[i]);
            L.data[i - del] = L.data[i];
        }
    }
    L.length = L.length - del;
}

// 06
bool merge(SeqList& La, SeqList& Lb, SeqList& Lm) {
    int lenA = La.length, lenB = Lb.length, size = Lm.maxSize;
    if (lenA + lenB > size) return false;
    int a = 0, b = 0, m = 0;
    while (a < lenA && b < lenB) {
        Lm.data[m++] = (La.data[a] <= Lb.data[b])
                        ? La.data[a++] : Lb.data[b++];
    }
    while (a < lenA) Lm.data[m++] = La.data[a++];
    while (b < lenB) Lm.data[m++] = Lb.data[b++];
    Lm.length = m;
    return true;
}

// 07
void reverse(ElemType arr[], int l, int r) {
    while (l < r) {
        ElemType tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        ++l, --r;
    }
}
bool exchange(ElemType arr[], int m, int n, int len) {
    if (m < 0 || n < 0 || m + n > len) return false;
    reverse(arr, 0, m + n - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, m + n - 1);
    return true;
}

// 08
bool searchI(SeqList& L, ElemType x) {
    int len = L.length();
    bool found = true;
    auto bin_search = [&](this auto&& bin_search, int l, int r) -> int {
        if (l > r) {
            found = false;
            return l;
        }
        int mid = (l + r)/2;
        if (L.data[mid] == x) return mid;
        if (L.data[mid] < x) return bin_search(mid + 1, r);
        else return bin_search(l, mid - 1);
    };
    int ret = bin_search(0, len - 1);
    if (found && ret < len - 1) {
        ElemType tmp = L.data[ret];
        L.data[ret] = L.data[ret + 1];
        L.data[ret + 1] = tmp;
    } 
    else if (!found) {
        for (int i = len; i > ret; --i) L.data[i] = L.data[i-1];
        L.data[ret] = x;
        ++L.length;
    }
    return true;
}

