#pragma once
#include "Employee.h"

class Admin : public Employee
{
public:

	Admin()
	{

	}
	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary)
	{

	}
	void addEmployee(Employee employee)
	{
		All_Employee.push_back(employee);
	}
	Employee* searchEmployee(int id)
	{
		for (EmployeeIt = All_Employee.begin(); EmployeeIt != All_Employee.end(); EmployeeIt++)
		{
			if (EmployeeIt->getId() == id)
			{
				return EmployeeIt._Ptr;
			}
		}
		return NULL;
	}
	void editEmployee(int id, string name, string password, double salary)
	{
		for (EmployeeIt = All_Employee.begin(); EmployeeIt != All_Employee.end(); EmployeeIt++)
		{
			if (EmployeeIt->getId() == id)
			{
				if (EmployeeIt->setName(name) && EmployeeIt->setPassword(password) && EmployeeIt->setSalary(salary))
				{
					cout << "\n*********************\n";
					cout << "Succesfull Edit\n";
					cout << "*********************\n\n";
				}
				else
				{
					cout << "\n*********************\n";
					cout << "Faild Edit\n";
					cout << "*********************\n\n";
				}
				return ;
			}
		}
	}
	void listEmployee()
	{
		for (EmployeeIt = All_Employee.begin(); EmployeeIt != All_Employee.end(); EmployeeIt++)
		{
			EmployeeIt->Display();
			cout << "\n**********************************************\n";
		}
	}

};
static vector<Admin> All_Admin;

static vector<Admin>::iterator  AdminIt;

static Admin _Admin;