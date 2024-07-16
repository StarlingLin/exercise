#define _CRT_SECURE_NO_WARNINGS

//����һ��n���������飬�ܼ�������k�β�����ÿ�β�������ѡ�������е�һ��ż�����������2��
//���в�����k�β����������е�������֮����С���������Сֵ��
//��һ��������������n��k(1<=n<=10^5, 1<=k<=10^9)��
//�ڶ�������n����������ʾ�����е�����ÿ����������10^9��

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minSumAfterOperations(int n, int k, vector<int>& arr) 
{
    long long sum = 0;

    for (int num : arr) 
    {
        sum += num;
    }

    for (int i = 0; i < k; ++i) 
    {
        int max_even_index = -1;
        for (int j = 0; j < n; ++j) 
        {
            if (arr[j] % 2 == 0 && (max_even_index == -1 || arr[j] > arr[max_even_index])) 
            {
                max_even_index = j;
            }
        }

        if (max_even_index == -1) 
        {
            break;
        }

        sum -= arr[max_even_index] / 2;
        arr[max_even_index] /= 2;
    }

    return sum;
}

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) 
    {
        cin >> arr[i];
    }

    cout << minSumAfterOperations(n, k, arr) << endl;
    return 0;
}
