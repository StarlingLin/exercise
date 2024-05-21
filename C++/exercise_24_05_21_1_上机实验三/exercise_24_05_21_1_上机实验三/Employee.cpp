#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include "Employee.h"

using namespace std;

Employee::Employee(const string& name, const string& id, const Date& birthDate)
	: m_name(name), m_id(id), m_birthDate(birthDate), m_birthBonus(0)
{
	time_t t = time(0);
	tm* now = localtime(&t);
	m_currentDate = Date(now->tm_year + 1900, now->tm_mon + 1, now->tm_mday);
	if (m_birthDate.GetMonth() == m_currentDate.GetMonth())
	{
		m_birthBonus = 100;
	}
}

Employee::~Employee()
{
}

const string& Employee::GetName() const
{
	return m_name;
}

const string& Employee::GetId() const
{
	return m_id;
}

const Date& Employee::GetBirthDate() const
{
	return m_birthDate;
}

SalariedEmployee::SalariedEmployee(const string& name, const string& id, const Date& birthDate, double weeklySalary)
	: Employee(name, id, birthDate), m_weeklySalary(weeklySalary)
{
}

SalariedEmployee::~SalariedEmployee()
{
}

double SalariedEmployee::Earnings() const
{
	return m_weeklySalary + m_birthBonus;
}

void SalariedEmployee::Print() const
{
	cout << "-----------------------------------" << endl;
	cout << "Salaried Employee" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Id: " << GetId() << endl;
	cout << "Birth Date: ";
	GetBirthDate().Print();
	cout << "Weekly Salary: " << m_weeklySalary << endl;
	cout << "Birth Bonus: " << m_birthBonus << endl;
	cout << "Earnings: " << Earnings() << endl;
	cout << "-----------------------------------" << endl;
}

double SalariedEmployee::GetWeeklySalary() const
{
	return m_weeklySalary;
}

HourlyEmployee::HourlyEmployee(const string& name, const string& id, const Date& birthDate, double hourlySalary, double hours)
	: Employee(name, id, birthDate), m_hourlySalary(hourlySalary), m_hours(hours)
{
}

HourlyEmployee::~HourlyEmployee()
{
}

double HourlyEmployee::Earnings() const
{
	if (m_hours <= 40)
	{
		return m_hourlySalary * m_hours + m_birthBonus;
	}
	else
	{
		return 40 * m_hourlySalary + (m_hours - 40) * m_hourlySalary * 1.5 + m_birthBonus;
	}
}

void HourlyEmployee::Print() const
{
	cout << "-----------------------------------" << endl;
	cout << "Hourly Employee" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Id: " << GetId() << endl;
	cout << "Birth Date: ";
	GetBirthDate().Print();
	cout << "Hourly Salary: " << m_hourlySalary << endl;
	cout << "Hours: " << m_hours << endl;
	cout << "Birth Bonus: " << m_birthBonus << endl;
	cout << "Earnings: " << Earnings() << endl;
	cout << "-----------------------------------" << endl;
}

double HourlyEmployee::GetHourlySalary() const
{
	return m_hourlySalary;
}

double HourlyEmployee::GetHours() const
{
	return m_hours;
}

CommissionEmployee::CommissionEmployee(const string& name, const string& id, const Date& birthDate, double sales, double commission)
	: Employee(name, id, birthDate), m_sales(sales), m_commission(commission)
{
}

CommissionEmployee::~CommissionEmployee()
{
}

double CommissionEmployee::Earnings() const
{
	return m_sales * m_commission + m_birthBonus;
}

void CommissionEmployee::Print() const
{
	cout << "-----------------------------------" << endl;
	cout << "Commission Employee" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Id: " << GetId() << endl;
	cout << "Birth Date: ";
	GetBirthDate().Print();
	cout << "Sales: " << m_sales << endl;
	cout << "Commission: " << m_commission << endl;
	cout << "Birth Bonus: " << m_birthBonus << endl;
	cout << "Earnings: " << Earnings() << endl;
	cout << "-----------------------------------" << endl;
}

double CommissionEmployee::GetSales() const
{
	return m_sales;
}

double CommissionEmployee::GetCommission() const
{
	return m_commission;
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string& name, const string& id, const Date& birthDate, double sales, double commission, double baseSalary)
	: CommissionEmployee(name, id, birthDate, sales, commission), m_baseSalary(baseSalary)
{
}

BasePlusCommissionEmployee::~BasePlusCommissionEmployee()
{
}

double BasePlusCommissionEmployee::Earnings() const
{
	return m_baseSalary * 1.1 + GetSales() * GetCommission() + m_birthBonus;
}

void BasePlusCommissionEmployee::Print() const
{
	cout << "-----------------------------------" << endl;
	cout << "Base Plus Commission Employee" << endl;
	cout << "Name: " << GetName() << endl;
	cout << "Id: " << GetId() << endl;
	cout << "Birth Date: ";
	GetBirthDate().Print();
	cout << "Sales: " << GetSales() << endl;
	cout << "Commission: " << GetCommission() << endl;
	cout << "Base Salary: " << m_baseSalary << endl;
	cout << "Base Salary after Bonus: " << m_baseSalary * 1.1 << endl;
	cout << "Birth Bonus: " << m_birthBonus << endl;
	cout << "Earnings: " << Earnings() << endl;
	cout << "-----------------------------------" << endl;
}

double BasePlusCommissionEmployee::GetBaseSalary() const
{
	return m_baseSalary;
}