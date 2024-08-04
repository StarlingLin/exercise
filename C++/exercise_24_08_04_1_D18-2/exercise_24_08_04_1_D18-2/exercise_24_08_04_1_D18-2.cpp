#define _CRT_SECURE_NO_WARNINGS

//n个橘子，每个有甜度值和酸度值，吃k个，使甜度值总和最大，如果多种甜度值总和最大方案，选酸度值总和最小的那一个
//输入：第一行n，k，第二行n个酸度值，第三行n个甜度值
//输出：最终方案的酸度值总和和甜度值总和

//超时
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
