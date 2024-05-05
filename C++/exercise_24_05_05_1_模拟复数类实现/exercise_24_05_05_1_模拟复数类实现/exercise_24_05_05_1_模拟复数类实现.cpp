#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
	Complex(1, 2).display();
	Complex(3, 4).display();
	(Complex(1, 2) + Complex(3, 4)).display();
	(Complex(1, 2) - Complex(3, 4)).display();
	(Complex(1, 2) * Complex(3, 4)).display();
	(Complex(1, 2) / Complex(3, 4)).display();
	(-Complex(1, 2)).display();
	(Complex(1, 2) += Complex(3, 4)).display();
	(Complex(1, 2) -= Complex(3, 4)).display();
	(Complex(1, 2) *= Complex(3, 4)).display();
	(Complex(1, 2) /= Complex(3, 4)).display();
	(++Complex(1, 2)).display();
	(Complex(1, 2)++).display();
	(--Complex(1, 2)).display();
	(Complex(1, 2)--).display();
	cout << (Complex(1, 2) == Complex(3, 4)) << endl;
	cout << (Complex(1, 2) != Complex(3, 4)) << endl;
	cout << (Complex(1, 2) > Complex(3, 4)) << endl;
	cout << (Complex(1, 2) < Complex(3, 4)) << endl;
	Complex c(1, 2);
	c = Complex(3, 4);
	c.display();
}