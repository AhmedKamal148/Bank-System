#pragma once
#include "FilesHelper.h"
class EmployeeManager
{
public:
	static void printEmployeeMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tEmployee Functions\n";
		cout << "1-Add New Client\n";
		cout << "2-List Of All Clients\n";
		cout << "3-Search For A Client\n";
		cout << "4-Edit Client\n";
		cout << "5-Display\n";
		cout << "6-Update Password\n";
		cout << "7-Logout\n";
		cout << endl;
	}
	static void newClient(Employee *employee)
	{
		Client client;
		string name, password;
		double balance;
		int id;
		cout << "Enter New Client\n\n";
		cout << "Name : ";
		cin >> name;
		cout << "Password : ";
		cin >> password;
		cout << "Balance : ";
		cin >> balance;
		if (client.setName(name) && client.setPassword(password) && client.setBalance(balance))
		{
			id = FilesHelper::getLast("client_id.txt");
			client.setId(id + 1);
			FilesHelper::saveLast("client_id.txt", id + 1);
			employee->addClient(client);
			cout << "\n*******************\n";
			cout << "Client Accepted\n";
			cout << "*******************\n\n";
		}
		else
		{
			cout << "\n**************************\n";
			cout << "Client Not Accepted\n";
			cout << "**************************\n\n";
		}
		
	}
	static void listAllClients(Employee* employee)
	{
		employee->listClient();
	}
	static void searchForClient(Employee* employee)
	{
		int id;
		cout << "Client Id : ";
		cin >> id;
		Client* client = employee->Search(id);
		if (client == NULL)
		{
			cout << "\n**************************\n";
			cout << "Client Not Found\n";
			cout << "**************************\n\n";
		}
		else
		{
			client->Display();
		}
	}
	static void editClientInfo(Employee* employee)
	{
		int x;
		int id;
		string name, password;
		double balance;
		cout << "Enter Id : ";
		cin >> id;

		Client *client = employee->Search(id);

		if (client != NULL)
		{
			cout << "\nWhat You Want To Edit : \n";
			cout << "1-All data\n";
			cout << "2-Name\n";
			cout << "3-Password\n";
			cout << "4-Balance\n";

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
				cout << "\nEnter New balance : ";
				cin >> balance;
				employee->editClient(id, name, password, balance);

				break;
			}
			case 2:
			{
				cout << "\nEnter New Name : ";
				cin >> name;
				password = client->getPassword();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				break;
			}
			case 3:
			{
				cout << "\nEnter New Password : ";
				cin >> password;
				name = client->getName();
				balance = client->getBalance();
				employee->editClient(id, name, password, balance);
				break;
			}
			case 4:
			{
				cout << "\nEnter New Balance : ";
				cin >> balance;
				name = client->getName();
				password = client->getPassword();
				employee->editClient(id, name, password, balance);
				break;
			}
			default:
			{

				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				editClientInfo(employee);
				break;
			}
			}
		}
		else
		{
			cout << "\n************************\n";
			cout << "Client not found\n\n";
			cout << "************************\n\n";
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				editClientInfo(employee);
			}
			else if (x == 2)
			{
				printEmployeeMenu();
				employeeOptions(employee);
			}
			else
			{
				cout << "\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				printEmployeeMenu();
				employeeOptions(employee);
			}
		}
	}
	static bool employeeOptions(Employee *employee)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			newClient(employee);
			break;
		}
		case 2:
		{
			system("cls");
			listAllClients(employee);
			break;
		}
		case 3:
		{
			system("cls");
			searchForClient(employee);
			break;
		}
		case 4:
		{
			system("cls");
			editClientInfo(employee);
			break;
		}
		case 5:
		{
			system("cls");
			employee->Display();
			break;
		}
		case 6:
		{
			system("cls");
			updatePassword(employee);
			break;
		}
		case 7:
		{
			return true;
		}
		default:
		{
			cout << "\nYour Choise Not Found In List\n";
			employeeOptions(employee);
		}
		}
		Back(employee);
	}
	static void Back(Employee* employee)
	{
		system("pause");
		printEmployeeMenu();
		employeeOptions(employee);
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
	static Employee* Login(int id, string password)
	{
		Employee* employeeptr = _Admin.searchEmployee(id);

		if (employeeptr == NULL)
		{
			cout << "\nIncorrect Id Or Password\n";
			return NULL;
		}
		else
		{
			if (employeeptr->getPassword() == password)
			{
				return employeeptr;
			}
			else
			{
				cout << "\nIncorrect Id Or Password\n";
				return NULL;
			}
		}
	}
};

