#define _CRT_SECURE_NO_WARNINGS

//����6�����ӣ����Ƿ����������������(������ȡ�õĹ��Ӳ�һ����˳��)
//��һ������һ������t����ʾ��t�����ݣ�������t�У�ÿ������6����������ʾ6�����ӵĳ���
//���t�У�ÿ�����Yes��No����ʾ�Ƿ����������������

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