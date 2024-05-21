#define _CRT_SECURE_NO_WARNINGS

/*
* 为某公司设计雇员工资发放系统。
* 每个雇员的基本信息包括：姓名（name），工号（id）。
* 雇员的收入取决于雇员的类型。该公司共有四类雇员：
* 周薪雇员（SalariedEmployee）：收入=固定周薪。
* 时薪雇员（HourlyEmployee）：若工作40小时以下，收入=小时数*每小时薪水；若工作40小时以上，收入=40*每小时薪水+（小时数-40）*每小时薪水*150%。
* 佣金雇员（CommissionEmployee）：收入=销售量*每个商品的销售佣金。
* 带底薪佣金雇员（BasePlusCommissionEmployee）：收入=底薪+销售量*每个商品的销售佣金。
* 要求：
* 建立雇员继承层次，每个类包含计算工资和显示输出的功能，可以计算和显示输出公司雇员（Employee）的每周收入。
* 输出时要显示该类雇员的所有信息。（包括雇员类型、姓名、工号、工资各项明细），写出主函数测试各类。
* 在雇员基本信息中增加雇员的生日（birthDate），并设计日期类（Date）来表示生日。
* 在主函数中创建一个容器用来管理公司各种雇员对象，多态地计算并输出每个雇员的工资。
* 如果雇员的生日在本月，就奖给该雇员100元。
* 同时，在本次工资发放阶段，公司决定奖励带薪佣金雇员，把他们的基本工资提高10%。
* 使用抽象基类，纯虚函数，虚函数，多态等面向对象的特性。
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