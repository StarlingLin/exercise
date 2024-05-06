#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdarg>
#include "Polynomial.h"

using namespace std;

int Polynomial::count = 0;

/// <summary>
/// 构造函数
/// </summary>
/// <param name="n">多项式的次数</param>
/// <param name="a">多项式的系数</param>
Polynomial::Polynomial(int n, double* a)
{
	this->n = n;
	this->a = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		this->a[i] = a[i];
	}
	count++;
}

/// <summary>
/// 构造函数（可变参数列表）
/// </summary>
/// <param name="n">多项式次数</param>
/// <param name="a">常数项</param>
/// <param name="">后续参数（由低次到高次）</param>
Polynomial::Polynomial(int n, double a, ...)
{
	this->n = n;
	this->a = new double[n + 1];
	va_list args;
	va_start(args, a);
	this->a[0] = a;
	for (int i = 1; i <= n; i++)
	{
		this->a[i] = va_arg(args, double);
	}
	va_end(args);
	count++;
}

/// <summary>
/// 拷贝构造函数
/// </summary>
/// <param name="p">多项式对象</param>
Polynomial::Polynomial(const Polynomial& p)
{
	this->n = p.n;
	this->a = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		this->a[i] = p.a[i];
	}
	count++;
}

/// <summary>
/// 析构函数
/// </summary>
Polynomial::~Polynomial()
{
	delete[] a;
	count--;
}

/// <summary>
/// 打印多项式
/// </summary>
void Polynomial::print()
{
	if (n == 0)
	{
		cout << '0' << endl;
		return;
	}
	for (int i = n; i >= 0; i--)
	{
		if (a[i] == 0)	// 系数为0的项不输出
		{
			continue;
		}
		if (i == n)	// 最高次项
		{
			if (a[i] == 1)
			{
				cout << "x^" << i;
			}
			else if (a[i] == -1)
			{
				cout << "-x^" << i;
			}
			else
			{
				cout << a[i] << "x^" << i;
			}
		}
		else if (i == 1)	// 一次项
		{
			if (a[i] == 1)
			{
				cout << "+x";
			}
			else if (a[i] == -1)
			{
				cout << "-x";
			}
			else if (a[i] > 0)
			{
				cout << "+" << a[i] << "x";
			}
			else
			{
				cout << a[i] << "x";
			}
		}
		else if (i == 0)	// 常数项
		{
			if (a[i] > 0)
			{
				cout << "+" << a[i];
			}
			else
			{
				cout << a[i];
			}
		}
		else	// 平凡项
		{
			if (a[i] == 1)
			{
				cout << "+x^" << i;
			}
			else if (a[i] == -1)
			{
				cout << "-x^" << i;
			}
			else if (a[i] > 0)
			{
				cout << "+" << a[i] << "x^" << i;
			}
			else
			{
				cout << a[i] << "x^" << i;
			}
		}
	}
	cout << endl;
}

/// <summary>
/// 计算多项式的值
/// </summary>
/// <param name="x">自变量x</param>
/// <returns>多项式的值</returns>
double Polynomial::calc(double x)
{
	double result = 0;
	for (int i = 0; i <= n; i++)
	{
		result += a[i] * pow(x, i);
	}
	return result;
}

/// <summary>
/// 重载“+”运算符实现多项式的加法
/// </summary>
/// <param name="p">多项式对象</param>
/// <returns>相加后的多项式对象</returns>
Polynomial Polynomial::operator+(const Polynomial& p)
{
	int max_n = n > p.n ? n : p.n;
	int min_n = n < p.n ? n : p.n;
	double* max_a = n >= p.n ? a : p.a;
	double* min_a = n < p.n ? a : p.a;
	double* result_a = new double[max_n + 1];
	for (int i = 0; i <= min_n; i++)
	{
		result_a[i] = max_a[i] + min_a[i];
	}
	for (int i = min_n + 1; i <= max_n; i++)
	{
		result_a[i] = max_a[i];
	}
	for (int i = max_n; i > 0; i--)
	{
		if (result_a[i] != 0)
		{
			break;
		}
		--max_n;
	}
	Polynomial result(max_n, result_a);
	delete[] result_a;
	return result;
}

/// <summary>
/// 重载“-”运算符实现多项式的减法
/// </summary>
/// <param name="p">多项式对象</param>
/// <returns>相减后的多项式对象</returns>
Polynomial Polynomial::operator-(const Polynomial& p)
{
	int max_n = n > p.n ? n : p.n;
	int min_n = n < p.n ? n : p.n;
	double* max_a = n >= p.n ? a : p.a;
	double* min_a = n < p.n ? a : p.a;
	double* result_a = new double[max_n + 1];
	for (int i = 0; i <= min_n; i++)
	{
		result_a[i] = max_a[i] - min_a[i];
	}
	for (int i = min_n + 1; i <= max_n; i++)
	{
		result_a[i] = max_a[i];
	}
	for (int i = max_n; i > 0; i--)
	{
		if (result_a[i] != 0)
		{
			break;
		}
		--max_n;
	}
	Polynomial result(max_n, result_a);
	delete[] result_a;
	return result;
}

/// <summary>
/// 重载“*”运算符实现多项式的乘法
/// </summary>
/// <param name="p">多项式对象</param>
/// <returns>相乘后的多项式对象</returns>
Polynomial Polynomial::operator*(const Polynomial& p)
{
	int result_n = n + p.n;
	double* result_a = new double[result_n + 1];
	memset(result_a, 0, sizeof(double) * (result_n + 1));
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= p.n; j++)
		{
			result_a[i + j] += a[i] * p.a[j];
		}
	}
	Polynomial result(result_n, result_a);
	delete[] result_a;
	return result;
}

/// <summary>
/// 重载“=”运算符实现赋值运算
/// </summary>
/// <param name="p">多项式对象</param>
/// <returns></returns>
Polynomial& Polynomial::operator=(const Polynomial& p)
{
	if (this == &p)
	{
		return *this;
	}
	delete[] a;
	n = p.n;
	a = new double[n + 1];
	for (int i = 0; i <= n; i++)
	{
		a[i] = p.a[i];
	}
	return *this;
}