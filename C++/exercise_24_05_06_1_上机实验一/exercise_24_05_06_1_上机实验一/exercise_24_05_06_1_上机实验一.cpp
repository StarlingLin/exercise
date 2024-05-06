#define _CRT_SECURE_NO_WARNINGS

/*
* �����¶���ʽ��д�ඨ�壺
* a_0 + a_1 * x + a_2 * x^2 + �� + a_n * x^n
* ���У�nΪ����ʽ�Ĵ�����������¹��ܣ�
* - �ɴ洢�����Ķ���ʽ����˳���
* - ���幹�캯���������������������캯����
* - ����һ��static��Ա�洢����Ķ���ʽ������
* - ����һ����Ա�����������ʽ�����ɲ���-x^4-6x^3+5�ĸ�ʽ�����Ҫ����
* - ����һ����Ա�����������ʽ��ֵ��
* - ���ء�+����-����*�������ʵ�ֶ���ʽ�ļӼ������㡣
* - ���ء�=�������ʵ�ָ�ֵ���㡣
* - ��main������д���Դ��롣
* Ҫ����ö��ļ�ʵ�֡�
* ������Щ������������Ϊconst��������ĳ�����������Ϊ��Ԫ������
*/

#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	double a1[] = { 1, 2, 3, 4, 5 };
	double a2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Polynomial p1(4, a1);
	Polynomial p2(9, a2);
	Polynomial p3(4, 1.1, 2.2, 3.3, 4.4, 5.5);
	Polynomial p4(p1);
	Polynomial p5 = p1 + p2;
	Polynomial p6 = p1 + p4;
	Polynomial p7 = p1 - p2;
	Polynomial p8 = p1 - p4;
	Polynomial p9 = p1 * p2;
	Polynomial p10 = p1 * p4;
	p1.print();
	p2.print();
	p3.print();
	p4.print();
	p5.print();
	p6.print();
	p7.print();
	p8.print();
	p9.print();
	p10.print();

	return 0;
}