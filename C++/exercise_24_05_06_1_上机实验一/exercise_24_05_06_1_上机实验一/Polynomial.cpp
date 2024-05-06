#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdarg>
#include "Polynomial.h"

using namespace std;

int Polynomial::count = 0;

/// <summary>
/// ���캯��
/// </summary>
/// <param name="n">����ʽ�Ĵ���</param>
/// <param name="a">����ʽ��ϵ��</param>
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
/// ���캯�����ɱ�����б�
/// </summary>
/// <param name="n">����ʽ����</param>
/// <param name="a">������</param>
/// <param name="">�����������ɵʹε��ߴΣ�</param>
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
/// �������캯��
/// </summary>
/// <param name="p">����ʽ����</param>
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
/// ��������
/// </summary>
Polynomial::~Polynomial()
{
	delete[] a;
	count--;
}

/// <summary>
/// ��ӡ����ʽ
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
		if (a[i] == 0)	// ϵ��Ϊ0������
		{
			continue;
		}
		if (i == n)	// ��ߴ���
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
		else if (i == 1)	// һ����
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
		else if (i == 0)	// ������
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
		else	// ƽ����
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
/// �������ʽ��ֵ
/// </summary>
/// <param name="x">�Ա���x</param>
/// <returns>����ʽ��ֵ</returns>
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
/// ���ء�+�������ʵ�ֶ���ʽ�ļӷ�
/// </summary>
/// <param name="p">����ʽ����</param>
/// <returns>��Ӻ�Ķ���ʽ����</returns>
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
/// ���ء�-�������ʵ�ֶ���ʽ�ļ���
/// </summary>
/// <param name="p">����ʽ����</param>
/// <returns>�����Ķ���ʽ����</returns>
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
/// ���ء�*�������ʵ�ֶ���ʽ�ĳ˷�
/// </summary>
/// <param name="p">����ʽ����</param>
/// <returns>��˺�Ķ���ʽ����</returns>
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
/// ���ء�=�������ʵ�ָ�ֵ����
/// </summary>
/// <param name="p">����ʽ����</param>
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