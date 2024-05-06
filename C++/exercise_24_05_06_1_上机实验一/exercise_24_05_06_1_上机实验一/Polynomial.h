#pragma once

class Polynomial
{
public:
	Polynomial(int n, double* a);
	Polynomial(int n, double a, ...);	// �ɱ�����б�����ȫ������ά����������⣬���׵��ԣ�������չ�������ع������ײ��ԣ����ײ��𣬲���ά����
	Polynomial(const Polynomial& p);
	~Polynomial();
	void print();
	double calc(double x);
	Polynomial operator+(const Polynomial& p);
	Polynomial operator-(const Polynomial& p);
	Polynomial operator*(const Polynomial& p);
	Polynomial& operator=(const Polynomial& p);
	static int count;	// �洢����Ķ���ʽ����

private:
	int n;		// ����ʽ�Ĵ���
	double* a;	// ����ʽ��ϵ��
};