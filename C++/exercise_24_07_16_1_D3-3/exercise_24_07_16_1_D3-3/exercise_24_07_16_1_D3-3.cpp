#define _CRT_SECURE_NO_WARNINGS

//给定一个n个数的数组，总计最多进行k次操作，每次操作可以选择数组中的一个偶数，将其除以2。
//进行不超过k次操作后，数组中的所有数之和最小，求这个最小值。
//第一行输入两个整数n和k(1<=n<=10^5, 1<=k<=10^9)。
//第二行输入n个整数，表示数组中的数，每个数不超过10^9。

//复杂度过高，无法通过测试用例
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int minSumAfterOperations(int n, int k, vector<int>& arr) 
//{
//    int sum = 0;
//
//    for (int num : arr) 
//    {
//        sum += num;
//    }
//
//    for (int i = 0; i < k; ++i) 
//    {
//        int max_even_index = -1;
//        for (int j = 0; j < n; ++j) 
//        {
//            if (arr[j] % 2 == 0 && (max_even_index == -1 || arr[j] > arr[max_even_index])) 
//            {
//                max_even_index = j;
//            }
//        }
//
//        if (max_even_index == -1) 
//        {
//            break;
//        }
//
//        sum -= arr[max_even_index] / 2;
//        arr[max_even_index] /= 2;
//    }
//
//    return sum;
//}
//
//int main() 
//{
//    int n, k;
//    cin >> n >> k;
//    vector<int> arr(n);
//
//    for (int i = 0; i < n; ++i) 
//    {
//        cin >> arr[i];
//    }
//
//    cout << minSumAfterOperations(n, k, arr) << endl;
//    return 0;
//}

//建立最大堆存放偶数，每次取出最大值，除以2，若为偶数再放回堆中，最多k次操作

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long minSumAfterOperations(int n, int k, vector<int>& arr)
{
	long long sum = 0;
	priority_queue<int> pq;

	for (int num : arr)
	{
		sum += num;
		if (num % 2 == 0)
		{
			pq.push(num);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		if (pq.empty())
		{
			break;
		}

		int max_even = pq.top();
		pq.pop();
		sum -= max_even / 2;
		if (max_even / 2 % 2 == 0)
			pq.push(max_even / 2);
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