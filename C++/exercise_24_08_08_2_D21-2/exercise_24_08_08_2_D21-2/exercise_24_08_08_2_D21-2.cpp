#define _CRT_SECURE_NO_WARNINGS

//��������������{A}+{B}��ͬһ�������в�����������ͬ��Ԫ�ء�
//�������У���һ������������n, m���ڶ�����n������Ϊ����A�е�Ԫ�أ���������m������Ϊ����B�е�Ԫ��
//�������

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> A(n), B(m);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < m; i++)
		cin >> B[i];
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	B.erase(unique(B.begin(), B.end()), B.end());
	vector<int> C;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size())
	{
		if (A[i] < B[j])
		{
			C.push_back(A[i]);
			i++;
		}
		else if (A[i] > B[j])
		{
			C.push_back(B[j]);
			j++;
		}
		else
		{
			C.push_back(A[i]);
			i++;
			j++;
		}
	}
	while (i < A.size())
	{
		C.push_back(A[i]);
		i++;
	}
	while (j < B.size())
	{
		C.push_back(B[j]);
		j++;
	}
	for (int i = 0; i < C.size(); i++)
		cout << C[i] << " ";
	cout << endl;

	return 0;
}