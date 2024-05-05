#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex(double real, double imag)
{
	this->real = real;
	this->imag = imag;
}

Complex Complex::operator+(const Complex& c) const
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex& c) const
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex& c) const
{
	return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

Complex Complex::operator/(const Complex& c) const
{
	double r = c.real * c.real + c.imag * c.imag;
	return Complex((real * c.real + imag * c.imag) / r, (imag * c.real - real * c.imag) / r);
}

Complex Complex::operator-() const
{
	return Complex(-real, -imag);
}

Complex& Complex::operator+=(const Complex& c)
{
	real += c.real;
	imag += c.imag;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	real -= c.real;
	imag -= c.imag;
	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	double r = real * c.real - imag * c.imag;
	imag = real * c.imag + imag * c.real;
	real = r;
	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	double r = c.real * c.real + c.imag * c.imag;
	double re = (real * c.real + imag * c.imag) / r;
	imag = (imag * c.real - real * c.imag) / r;
	real = re;
	return *this;
}

Complex& Complex::operator++()
{
	++real;
	return *this;
}

Complex Complex::operator++(int)
{
	Complex temp(*this);
	++real;
	return temp;
}

Complex& Complex::operator--()
{
	--real;
	return *this;
}

Complex Complex::operator--(int)
{
	Complex temp(*this);
	--real;
	return temp;
}

bool Complex::operator==(const Complex& c) const
{
	return real == c.real && imag == c.imag;
}

bool Complex::operator!=(const Complex& c) const
{
	return !(*this == c);
}

bool Complex::operator>(const Complex& c) const
{
	return real * real + imag * imag > c.real * c.real + c.imag * c.imag;
}

bool Complex::operator<(const Complex& c) const
{
	return real * real + imag * imag < c.real * c.real + c.imag * c.imag;
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	imag = c.imag;
	return *this;
}

void Complex::display() const
{
	std::cout << "(" << real << ", " << imag << "i)" << std::endl;
}