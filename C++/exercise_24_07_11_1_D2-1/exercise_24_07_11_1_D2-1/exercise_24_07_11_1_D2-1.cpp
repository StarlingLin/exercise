#define _CRT_SECURE_NO_WARNINGS

//��ݣ�1kg���ڰ��𲽼�20Ԫ���㣬��������ÿǧ��1Ԫ������Ӽ�������5Ԫ������������ȡ����
//�����һ��Ϊһ�������ȸ�����a��һ���ַ�b��a��ʾ���������b��ʾ�Ƿ�Ӽ���bΪy��ʾ�Ӽ���bΪn��ʾ���Ӽ���

#include <iostream>

using namespace std;

int main() 
{
	float weight;
	char urgent;
	cin >> weight >> urgent;
	weight = (int)(weight + 0.999999);
	if (urgent == 'y')
		cout << 20 + 5 + (weight - 1) << endl;
	else
		cout << 20 + weight - 1 << endl;
	return 0;
}