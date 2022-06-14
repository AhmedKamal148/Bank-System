#pragma once
#include "EmployeeManager.h"
class AdminManager : public EmployeeManager
{
public:
	static void printAdminMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tAdmin Functions\n";
		cout << "1-Add New Client\n";
		cout << "2-List Of All Clients\n";
		cout << "3-Search For A Client\n";
		cout << "4-Edit Client\n";
		cout << "5-Add New Employee\n";
		cout << "6-List Of All Employee\n";
		cout << "7-Search For A Employee\n";
		cout << "8-Edit Employee\n";
		cout << "9-Display\n";
		cout << "10-Update Password\n";
		cout << "11-Logout\n";
		cout << endl;
	}
	static void newEmployee(Admin* admin)
	{
		Employee employee;
		string name, password;
		double salary;
		int id;
		cout << "Enter New Employee\n\n";
		cout << "Name : ";
		cin >> name;
		cout << "Password : ";
		cin >> password;
		cout << "Salary : ";
		cin >> salary;
		if (employee.setName(name) && employee.setPassword(password) && employee.setSalary(salary))
		{
			id = FilesHelper::getLast("Employee_id.txt");
			employee.setId(id + 1);
			FilesHelper::saveLast("Employee_id.txt", id + 1);
			admin->addEmployee(employee);
			cout << "\n*******************\n";
			cout << "Employee Accepted\n";
			cout << "*******************\n\n";
		}
		else
		{
			cout << "\n**************************\n";
			cout << "Employee Not Accepted\n";
			cout << "**************************\n\n";
		}

	}
	static void listAllEmployee(Admin* admin)
	{
		admin->listEmployee();
	}
	static void searchForEmployee(Admin* admin)
	{
		int id;
		cout << "Employee Id : ";
		cin >> id;
		Employee* employee = admin->searchEmployee(id);
		if (employee == NULL)
		{
			cout << "\n**************************\n";
			cout << "Employee Not Found\n";
			cout << "**************************\n\n";
		}
		else
		{
			employee->Display();
		}
	}
	static void editEmployeeInfo(Admin* admin)
	{
		int x;
		int id;
		string name, password;
		double salary;
		cout << "Enter Id : ";
		cin >> id;

		Employee* employee = admin->searchEmployee(id);

		if (employee != NULL)
		{
			cout << "\nWhat You Want To Edit : \n";
			cout << "1-All data\n";
			cout << "2-Name\n";
			cout << "3-Password\n";
			cout << "4-Salary\n";

			cout << "\nEnter Your Choise : ";
			cin >> x;

			switch (x)
			{
			case 1:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				cout << "\nEnter New Password : ";
				cin >> password;
				cout << "\nEnter New Salary : ";
				cin >> salary;
				admin->editEmployee(id, name, password, salary);
				break;
			}
			case 2:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				password = employee->getPassword();
				salary = employee->getSalary();
				admin->editEmployee(id, name, password, salary);
				break;
			}
			case 3:
			{
				cout << "\nEnter New Password : ";
				cin >> password;
				name = employee->getName();
				salary = employee->getSalary();
				admin->editEmployee(id, name, password, salary);
				break;
			}
			case 4:
			{
				cout << "\nEnter New Salary : ";
				cin >> salary;
				name = employee->getName();
				password = employee->getPassword();
				admin->editEmployee(id, name, password, salary);
				break;
			}
			default:
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				editEmployeeInfo(admin);
				break;
			}
			}
		}
		else
		{
			cout << "\n************************\n";
			cout << "Employee not found\n\n";
			cout << "************************\n\n";
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				editEmployeeInfo(admin);
			}
			else if (x == 2)
			{
				printAdminMenu();
				AdminOptions(admin);
			}
			else
			{
				cout << "\nYour Choise Not Found In List\n\n";
				system("pause");
				printAdminMenu();
				AdminOptions(admin);
			}
		}
	}
	static bool AdminOptions(Admin* admin)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			newClient(admin);
			break;
		}
		case 2:
		{
			system("cls");
			listAllClients(admin);
			break;
		}
		case 3:
		{
			system("cls");
			searchForClient(admin);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(admin);
			break;
		}
		case 5:
		{
			system("cls");
			newEmployee(admin);
			break;
		}
		case 6:
		{
			system("cls");
			listAllEmployee(admin);
			break;
		}
		case 7:
		{
			system("cls");
			searchForEmployee(admin);
			break;
		}
		case 8:
		{
			system("cls");
			editEmployeeInfo(admin);
			break;
		}
		case 9:
		{
			system("cls");
			admin->Display();
			break;
		}
		case 10:
		{
			system("cls");
			updatePassword(admin);
			break;
		}
		case 11:
		{
			return true;
		}
		default:
		{
			cout << "\n*************************************\n";
			cout << "Your Choise Not Found In List\n";
			cout << "*************************************\n\n";
			AdminOptions(admin);
		}
		}
		Back(admin);
	}
	static void Back(Admin* admin)
	{
		system("pause");
		printAdminMenu();
		AdminOptions(admin);
	}
	static void updatePassword(Person* person)
	{
		string password;
		cout << "Enter New Password : ";
		cin >> password;
		if (person->setPassword(password))
		{
			cout << "\n*********************\n";
			cout << "Password Updated \n";
			cout << "*********************\n\n";
		}
	}
	static Admin* searchAdmin(int id)
	{
		for (AdminIt = All_Admin.begin(); AdminIt != All_Admin.end(); AdminIt++)
		{
			if (AdminIt->getId() == id)
			{
				return AdminIt._Ptr;
			}
		}
		return NULL;
	}
	static Admin* Login(int id, string password)
	{
		Admin* Adminptr = searchAdmin(id);

		if (Adminptr == NULL)
		{
			cout << "\n****************************\n";
			cout << "Incorrect Id Or Password\n";
			cout << "****************************\n\n";
			return NULL;
		}
		else
		{
			if (Adminptr->getPassword() == password)
			{
				return Adminptr;
			}
			else
			{
				cout << "\n****************************\n";
				cout << "Incorrect Id Or Password\n";
				cout << "****************************\n\n";
				return NULL;
			}
		}
	}
};

