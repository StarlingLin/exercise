#define _CRT_SECURE_NO_WARNINGS

//�⡢�������˺�С���ս
//ÿһ�ֹ��ȶ�С�칥�����������С�칥����Ȼ��С��չ��������ʹ��Ͷ������๥��
//�����Ĺ�������a����Ĺ�������b
//����������ֵ��h���������ֵ��k
//С�첻����������Ͷ�����ĳһ������������һ�˴������߻��С�췢��һ��10������������
//���������˿��Զ�С����ɵ��˺�

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���г�ʱ
int main() 
{
	long long a, b, h, k;
	cin >> a >> h >> b >> k;
	long long damage = 0;
	while (h > 0 && k > 0) 
	{
		damage += a + b;
		h -= b;
		if (h <= 0) {
			damage += 10 * b;
			break;
		}
		k -= a;
		if (k <= 0) {
			damage += 10 * a;
			break;
		}
	}
	cout << damage << endl;
	return 0;
}