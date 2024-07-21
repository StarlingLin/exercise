#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string solve(string s, string t)
    {
        int len1 = s.size();
        int len2 = t.size();
        int len = len1 + len2;
        int* a = new int[len]();  // ³õÊ¼»¯Îª0
        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                a[i + j + 1] += (s[i] - '0') * (t[j] - '0');
            }
        }
        for (int i = len - 1; i > 0; i--)
        {
            a[i - 1] += a[i] / 10;
            a[i] %= 10;
        }
        string res = "";
        int i = 0;
        while (i < len && a[i] == 0)
        {
            i++;
        }
        if (i == len)
        {
            return "0";
        }
        for (; i < len; i++)
        {
            res += a[i] + '0';
        }
        delete[] a;
        return res;
    }
};

int main()
{
	string s, t;
	cin >> s >> t;
	Solution solu;
	cout << solu.solve(s, t) << endl;
	return 0;
}