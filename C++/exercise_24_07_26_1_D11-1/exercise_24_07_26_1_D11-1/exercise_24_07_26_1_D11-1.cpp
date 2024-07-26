#define _CRT_SECURE_NO_WARNINGS

//n��ƻ��m�����ӣ�2��ƻ����1��������ɼ�ֵaԪ��ƴ�̣�1��ƻ����2��������ɼ�ֵbԪ��ƴ�̣���n��ƻ��m�����ӵ�����ֵ

#include <iostream>
#include <algorithm>

using namespace std;

//��ʱ
//int main() 
//{
//	int n, m, a, b;
//	cin >> n >> m >> a >> b;
//	int max = 0;
//	for (int i = 0; i <= n / 2; i++) 
//  {
//		for (int j = 0; j <= m / 2; j++)
//		{
//			if (i * 2 + j <= n && i + j * 2 <= m)
//			{
//				if (i * a + j * b > max) 
//				{
//					max = i * a + j * b;
//				}
//			}
//		}
//	}
//	cout << max << endl;
//	return 0;
//}

int main() 
{
	long long n, m, a, b;
	cin >> n >> m >> a >> b;
	long long ans = 0;
	for (int i = 0; i <= n / 2 && i < m; i++) 
    {
		long long j = min((m - i) / 2, (n - 2 * i));
		if (j >= 0)
			ans = max(ans, i * a + j * b);
	}
	cout << ans << endl;
	return 0;
}