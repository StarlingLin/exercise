#define _CRT_SECURE_NO_WARNINGS

//������������cost������cost[i]�����¥�ݵ�i��̨������������֧���Ĵ��ۣ��±��0��ʼ��
//ÿ��֧�����ۿ�����һ��̨�׻�������̨�ף�������¥�ݶ����������С���ۡ�
//�����һ��Ϊ����n������¥�ݵ�̨������1<=n<=100000��
//����ڶ���Ϊn�������������¥�ݵ�i��̨������������֧���Ĵ��ۣ�1<=cost[i]<=10000��


//DP

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int* cost = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	int* dp = new int[n];
	dp[0] = cost[0];
	dp[1] = cost[1];
	for (int i = 2; i < n; i++)
	{
		dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
	}

	cout << min(dp[n - 1], dp[n - 2]) << endl;

	delete[] cost;
	delete[] dp;

	return 0;
}
