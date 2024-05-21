#define _CRT_SECURE_NO_WARNINGS

/*
* Ϊĳ��˾��ƹ�Ա���ʷ���ϵͳ��
* ÿ����Ա�Ļ�����Ϣ������������name�������ţ�id����
* ��Ա������ȡ���ڹ�Ա�����͡��ù�˾���������Ա��
* ��н��Ա��SalariedEmployee��������=�̶���н��
* ʱн��Ա��HourlyEmployee����������40Сʱ���£�����=Сʱ��*ÿСʱнˮ��������40Сʱ���ϣ�����=40*ÿСʱнˮ+��Сʱ��-40��*ÿСʱнˮ*150%��
* Ӷ���Ա��CommissionEmployee��������=������*ÿ����Ʒ������Ӷ��
* ����нӶ���Ա��BasePlusCommissionEmployee��������=��н+������*ÿ����Ʒ������Ӷ��
* Ҫ��
* ������Ա�̳в�Σ�ÿ����������㹤�ʺ���ʾ����Ĺ��ܣ����Լ������ʾ�����˾��Ա��Employee����ÿ�����롣
* ���ʱҪ��ʾ�����Ա��������Ϣ����������Ա���͡����������š����ʸ�����ϸ����д�����������Ը��ࡣ
* �ڹ�Ա������Ϣ�����ӹ�Ա�����գ�birthDate��������������ࣨDate������ʾ���ա�
* ���������д���һ��������������˾���ֹ�Ա���󣬶�̬�ؼ��㲢���ÿ����Ա�Ĺ��ʡ�
* �����Ա�������ڱ��£��ͽ����ù�Ա100Ԫ��
* ͬʱ���ڱ��ι��ʷ��Ž׶Σ���˾����������нӶ���Ա�������ǵĻ����������10%��
* ʹ�ó�����࣬���麯�����麯������̬�������������ԡ�
*/

#include <iostream>
#include <vector>
#include "Date.h"
#include "Employee.h"

using namespace std;

void Test1()
{
	vector<Employee*> employees;
	employees.push_back(new SalariedEmployee("Tom", "001", Date(1990, 1, 1), 1000));
	employees.push_back(new HourlyEmployee("Jerry", "002", Date(1991, 3, 2), 10, 50));
	employees.push_back(new CommissionEmployee("Jack", "003", Date(1992, 5, 3), 100, 20));
	employees.push_back(new BasePlusCommissionEmployee("Rose", "004", Date(1993, 5, 4), 200, 5, 1000));

	for (auto employee : employees)
	{
		employee->Print();
	}

	for (auto employee : employees)
	{
		delete employee;
	}
}

int main() 
{
	Test1();

	return 0;
}