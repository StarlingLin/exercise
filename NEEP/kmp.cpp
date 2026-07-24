#include <string>
#include <vector>

using namespace std;

//-------------------------------
// 1.严蔚敏教材的神必下标和next定义
//-------------------------------

struct String
{
    char* ch; // 从1下标开始
    int len;
};

// next[j] := 第j个元素匹配失败时模式指针的下一个位置
// 因此研究前j-1个元素即可，也即求前j-1元素的LPS+1
// nextval仅为next的优化，将必定的连续跳转合并
int KMP_book(String text, String pattern, vector<int> nextval)
{
    int i = 1, j = 1;
    while (i <= text.len && j <= pattern.len)
    {
        if (!j || text.ch[i] == text.ch[j])
        {
            ++i;
            ++j;
        }
        else
            j = nextval[j];
    }
    if (j > pattern.len) return i - pattern.len;
    return 0;
}

vector<int> getNextVal(String pattern, vector<int> next)
{
    vector<int> nextval(pattern.len + 1);
    nextval[1] = 0;
    for (int j = 2; j <= pattern.len; ++j)
    {
        if (pattern.ch[next[j]] == pattern.ch[j])
            nextval[j] = nextval[next[j]];
        else
            nextval[j] = next[j];
    }
    return nextval;
}

vector<int> getNext(String pattern)
{
    vector<int> next(pattern.len + 1);
    next[1] = 0;
    int i = 1, j = 0;
    while (i < pattern.len)
    {
        if (!j || pattern.ch[i] == pattern.ch[j])
        {
            ++i, ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
    return next;
}

//-------------------------------
// 2.LPS数组定义，同算法导论π数组
//-------------------------------

// next[j] = lps[j-2]+1 由于下标起始不同，不然是j-1

vector<int> KMP_LPS(string text, string pattern)
{
    int lenP = pattern.length();
    vector<int> lps(lenP);
    for (int i = 1, j = 0; i < lenP; ++i)
    {
        while (j && pattern[j] != pattern[i]) j = lps[j - 1];
        if (pattern[j] == pattern[i]) ++j;
        lps[i] = j;
    }
    vector<int> pos;
    for (int i = 0, j = 0; i < text.length(); ++i)
    {
        while (j && pattern[j] != text[i]) j = lps[j - 1];
        if (pattern[i] == text[j]) ++j;
        if (j == lenP)
        {
            pos.push_back(i - lenP + 1);
            j = lps[j - 1];
        }
    }
    return pos;
}