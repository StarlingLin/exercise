#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Employee
{
public:
	Employee(const string& name, const string& id, const Date& birthDate);
	virtual ~Employee();

	virtual double Earnings() const = 0;
	virtual void Print() const = 0;

	const string& GetName() const;
	const string& GetId() const;
	const Date& GetBirthDate() const;

protected:
	string m_name;
	string m_id;
	Date m_birthDate;

	double m_birthBonus;
	Date m_currentDate;
};

class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(const string& name, const string& id, const Date& birthDate, double weeklySalary);
	virtual ~SalariedEmployee();

	virtual double Earnings() const override;
	virtual void Print() const override;

	double GetWeeklySalary() const;

private:
	double m_weeklySalary;
};

class HourlyEmployee : public Employee
{
public:
	HourlyEmployee(const string& name, const string& id, const Date& birthDate, double hourlySalary, double hours);
	virtual ~HourlyEmployee();

	virtual double Earnings() const override;
	virtual void Print() const override;

	double GetHourlySalary() const;
	double GetHours() const;

private:
	double m_hourlySalary;
	double m_hours;
};

class CommissionEmployee : public Employee
{
public:
	CommissionEmployee(const string& name, const string& id, const Date& birthDate, double sales, double commission);
	virtual ~CommissionEmployee();

	virtual double Earnings() const override;
	virtual void Print() const override;

	double GetSales() const;
	double GetCommission() const;

private:
	double m_sales;			// 销售量
	double m_commission;	// 每个商品的销售佣金
};

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
	BasePlusCommissionEmployee(const string& name, const string& id, const Date& birthDate, double sales, double commission, double baseSalary);
	virtual ~BasePlusCommissionEmployee();

	virtual double Earnings() const override;
	virtual void Print() const override;

	double GetBaseSalary() const;

private:
	double m_baseSalary;
};