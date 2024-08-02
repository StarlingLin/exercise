#define _CRT_SECURE_NO_WARNINGS

//给出区间[a, b]计算其中神奇数的数量
//神奇数的定义：存在不同位置的两个数位组成一个两位数，这个两位数是一个质数

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n < 11)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

bool isMagic(int n)
{
    if (n < 11)
        return false;
    vector<int> v;
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = i + 1; j < v.size(); j++)
            if (isPrime(v[i] * 10 + v[j]) || isPrime(v[j] * 10 + v[i]))
                return true;
    return false;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int sum = 0;
    for (int i = a; i <= b; i++)
        if (isMagic(i))
            sum++;
    cout << sum << endl;
    return 0;
}