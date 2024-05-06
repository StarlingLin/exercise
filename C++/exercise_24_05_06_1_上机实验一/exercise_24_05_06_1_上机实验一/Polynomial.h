#pragma once

class Polynomial
{
public:
	Polynomial(int n, double* a);
	Polynomial(int n, double a, ...);	// 可变参数列表（不安全，不易维护，不易理解，不易调试，不易扩展，不易重构，不易测试，不易部署，不易维护）
	Polynomial(const Polynomial& p);
	~Polynomial();
	void print();
	double calc(double x);
	Polynomial operator+(const Polynomial& p);
	Polynomial operator-(const Polynomial& p);
	Polynomial operator*(const Polynomial& p);
	Polynomial& operator=(const Polynomial& p);
	static int count;	// 存储定义的多项式数量

private:
	int n;		// 多项式的次数
	double* a;	// 多项式的系数
};