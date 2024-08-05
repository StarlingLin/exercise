#define _CRT_SECURE_NO_WARNINGS

//n�����ӣ�ÿ�������ֵ�����ֵ����k����ʹ���ֵ�ܺ��������������ֵ�ܺ���󷽰���ѡ���ֵ�ܺ���С����һ��
//���룺��һ��n��k���ڶ���n�����ֵ��������n�����ֵ
//��������շ��������ֵ�ܺͺ����ֵ�ܺ�

//��ʱ
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//
//using namespace std;
//
//int main()
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> sweet(n), sour(n);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> sour[i];
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> sweet[i];
//    }
//
//    vector<int> indices(n);
//    for (int i = 0; i < n; i++)
//    {
//        indices[i] = i;
//    }
//
//    int maxSweet = -1;
//    int minSour = INT_MAX;
//
//    do
//    {
//        int sumSweet = 0;
//        int sumSour = 0;
//        for (int i = 0; i < k; i++)
//        {
//            sumSweet += sweet[indices[i]];
//            sumSour += sour[indices[i]];
//        }
//        if (sumSweet > maxSweet || (sumSweet == maxSweet && sumSour < minSour))
//        {
//            maxSweet = sumSweet;
//            minSour = sumSour;
//        }
//    } while (next_permutation(indices.begin(), indices.end()));
//
//    cout << minSour << " " << maxSweet << endl;
//    return 0;
//}

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

typedef pair<int, int> PII; // <��ȣ����>

PII arr[N];
int n, k;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i].first;
    for (int i = 0; i < n; i++) cin >> arr[i].second;

    sort(arr, arr + n, [&](const PII& a, const PII& b)
        {
            if (a.second != b.second) return a.second > b.second;
            else return a.first < b.first;
        });

    long long s = 0, t = 0;
    for (int i = 0; i < k; i++)
    {
        s += arr[i].first;
        t += arr[i].second;
    }

    cout << s << " " << t << endl;

    return 0;
}