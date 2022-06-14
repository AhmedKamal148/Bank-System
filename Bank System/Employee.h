#pragma once
#include"Person.h"
#include<vector>
#include<fstream>
#include"Client.h"

class Employee : public Person
{
protected:
	double salary;

public:
	Employee()
	{
		salary = 5000;
	}

	Employee(int id, string name, string password, double salary) : Person(id, name, password)
	{
		setSalary(salary);
	}

	bool setSalary(double salary)
	{

		if (Validition::checkSalary(salary))
		{
			this->salary = salary;
			return true;
		}
		else
		{
			cout << "\n*************************************\n";
			cout << "Salary less than 5000\n";
			cout << "*************************************\n\n";
			return false;
		}

	}

	double getSalary()
	{
		return salary;
	}

	void Display()
	{
		Person::Display();
		cout << "Salary : " << salary << endl;
	}

	void addClient(Client client)
	{
		All_Client.push_back(client);
	}

	Client* Search(int id)
	{
		for (ClientIt = All_Client.begin(); ClientIt != All_Client.end(); ClientIt++)
		{
			if (ClientIt->getId() == id)
			{
				return ClientIt._Ptr;
			}
		}
		return NULL;
	}

	void listClient()
	{
		for (ClientIt = All_Client.begin(); ClientIt != All_Client.end(); ClientIt++)
		{
			ClientIt->Display();
			cout << "\n**********************************************\n";
		}
	}

	void editClient(int id, string name, string password, double balance)
	{
		for (ClientIt = All_Client.begin(); ClientIt != All_Client.end(); ClientIt++)
		{
			if (ClientIt->getId() == id)
			{
				if (ClientIt->setName(name) && ClientIt->setPassword(password) && ClientIt->setBalance(balance))
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
	
};
static vector<Employee> All_Employee;

static vector<Employee>::iterator  EmployeeIt;

static Employee _Employee;