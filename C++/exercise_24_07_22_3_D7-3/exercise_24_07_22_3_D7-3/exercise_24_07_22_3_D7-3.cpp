#define _CRT_SECURE_NO_WARNINGS

//给出6个棍子，问是否能组成两个三角形(三角形取用的棍子不一定按顺序)
//第一行输入一个整数t，表示有t组数据，接下来t行，每行输入6个整数，表示6根棍子的长度
//输出t行，每行输出Yes或No，表示是否能组成两个三角形

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTriangle(int a, int b, int c)
{
    return a + b > c && a + c > b && b + c > a;
}

bool canFormTwoTriangles(vector<int>& sticks)
{
    sort(sticks.begin(), sticks.end());
    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            for (int k = j + 1; k < 6; k++)
            {
                if (isTriangle(sticks[i], sticks[j], sticks[k]))
                {
                    vector<int> remaining;
                    for (int l = 0; l < 6; l++)
                    {
                        if (l != i && l != j && l != k)
                        {
                            remaining.push_back(sticks[l]);
                        }
                    }
                    if (isTriangle(remaining[0], remaining[1], remaining[2]))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> sticks(t, vector<int>(6));
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> sticks[i][j];
        }
    }
    for (int i = 0; i < t; i++)
    {
        if (canFormTwoTriangles(sticks[i]))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}