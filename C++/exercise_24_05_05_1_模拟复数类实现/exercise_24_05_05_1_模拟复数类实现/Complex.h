#pragma once

//ʵ�ָ����࣬��ɸ�����+��-��*��/��+=��-=��*=��/=��ǰ��++������++��ǰ��--������--��==�������жϣ���!=��>��ģ�Ƚϣ���<��=����ֵ������������

class Complex
{
public:
	Complex(double real = 0.0, double imag = 0.0);
	Complex operator+(const Complex& c) const;
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;
	Complex operator-() const;
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	Complex& operator++();
	Complex operator++(int);
	Complex& operator--();
	Complex operator--(int);
	bool operator==(const Complex& c) const;
	bool operator!=(const Complex& c) const;
	bool operator>(const Complex& c) const;
	bool operator<(const Complex& c) const;
	Complex& operator=(const Complex& c);
	void display() const;

private:
	double real;
	double imag;
};