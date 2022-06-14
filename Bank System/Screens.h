#pragma once
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "FileManager.h"
#include <Windows.h>

FileManager _Filemanager;
string name = " ";
class Screens
{
public:

	static void loginOptions()
	{
		cout << "\t\t\t\t\t\tLogin As\n";
		cout << "1 - Client\n\n";
		cout << "2 - Employee\n\n";
		cout << "3 - Admin\n\n";
		cout << "4 - Exit\n\n";
	}
	static int loginAs()
	{
		int x;
		cout << "Login As : ";
		cin >> x;

		switch (x)
		{
		case 1:
		{
			return 1;
			break;
		}
		case 2:
		{
			return 2;
			break;
		}
		case 3:
		{
			return 3;
			break;
		}
		case 4:
		{
			return 4;
			break;
		}
		default:
		{
			Invalid(x);
			break;
		}
		}
	}
	static void Invalid(int c)
	{
		cout << "\n\n*************************************\n";
		cout << "Your Choise Not Found In List\n";
		cout << "*************************************\n\n";
		loginAs();
	}
	static void LoginClient()
	{
		cout << "\t\t\t\t\t\tLogin Client Page\n";
		int id;
		string password;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;
		Client* client = ClientManger::login(id, password);
		if (client != NULL)
		{
			ClientManger::printClientMenu();
			if (ClientManger::clientOptions(client))
			{
				system("cls");
				name = client->getName();
				loginOptions();
				loginScreen(loginAs());
			}

		}
		else
		{
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			system("cls");
			if (x == 1)
			{
				LoginClient();
			}
			else if (x == 2)
			{
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
			else
			{
				cout << "\n\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
		}
	}
	static void LoginEmployee()
	{
		cout << "\t\t\t\t\t\tLogin Employee Page\n";
		int id;
		string password;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;
		Employee* employee = EmployeeManager::Login(id, password);
		if (employee != NULL)
		{
			EmployeeManager::printEmployeeMenu();
			if (EmployeeManager::employeeOptions(employee))
			{
				system("cls");
				name = employee->getName();
				loginOptions();
				loginScreen(loginAs());
			}
		}
		else
		{
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			if (x == 1)
			{
				LoginEmployee();
			}
			else if (x == 2)
			{
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
			else
			{
				cout << "\n\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
		}
	}
	static void LoginAdmin()
	{
		cout << "\t\t\t\t\t\tLogin Admin Page\n";
		int id;
		string password;
		cout << "Id : ";
		cin >> id;
		cout << "Password : ";
		cin >> password;

		Admin* admin = AdminManager::Login(id, password);
		if (admin != NULL)
		{
			AdminManager::printAdminMenu();
			if (AdminManager::AdminOptions(admin))
			{
				system("cls");
				name = admin->getName();
				loginOptions();
				loginScreen(loginAs());
			}
		}
		else
		{
			cout << "\n1 - Try Again\n";
			cout << "2 - Return\n";
			int x;
			cout << "\nEnter Your Choise : ";
			cin >> x;
			if (x == 1)
			{
				LoginAdmin();
			}
			else if(x == 2)
			{
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
			else
			{
				cout << "\n\n*************************************\n";
				cout << "Your Choise Not Found In List\n";
				cout << "*************************************\n\n";
				system("pause");
				system("cls");
				loginOptions();
				loginScreen(loginAs());
			}
		}
	}
	static void loginScreen(int c)
	{
		switch (c)
		{

		case 1:
		{
			system("cls");
			LoginClient();
			break;
		}
		case 2:
		{
			system("cls");
			LoginEmployee();
			break;
		}
		case 3:
		{
			system("cls");
			LoginAdmin();
			break;
		}
		case 4:
		{
			SayThank();
			_Filemanager.updateAllFiles();
		}

		}
	}
	static void SayThank()
	{
		system("cls");
		system("Color f4");
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t    ########  ##    ##   ######   ####    ##  ##   ##     ##    ##     ##     ##    ##\n";
		cout << "\t\t       ##     ##    ##  ##    ##  ## ##   ##  ##  ##       ##  ##    ##  ##   ##    ##\n";
		cout << "\t\t       ##     ########  ########  ##  ##  ##  ## #           ##     ##    ##  ##    ##\n";
		cout << "\t\t       ##     ##    ##  ##    ##  ##   ## ##  ##  ##         ##      ##  ##    ##  ##\n";
		cout << "\t\t       ##     ##    ##  ##    ##  ##    ####  ##   ##        ##        ##        ##\n";
		Sleep(2500);
		system("cls");
	}
	static void BankName()
	{
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t      ##     ##      ######      ##     ##     #######   ########  ####    ##  ##   ##\n";
		cout << "\t\t      ###   ###     ##    ##     ###   ###     ##    ##  ##    ##  ## ##   ##  ##  ##\n";
		cout << "\t\t      ## # # ##     ########     ## # # ##     #######   ########  ##  ##  ##  ## #\n";
		cout << "\t\t      ##  #  ##     ##    ##     ##  #  ##     ##    ##  ##    ##  ##   ## ##  ##  ##\n";
		cout << "\t\t      ##     ##  @  ##    ##  @  ##     ##     #######   ##    ##  ##    ####  ##   ##\n   ";
		Sleep(2500);
	}
	static void Welcome()
	{
		cout << "\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t##       ##   ######    ##      #######  ########   ##     ##   ######\n";
		cout << "\t\t\t##   #   ##   ##        ##      ##       ##    ##   ###   ###   ##\n";
		cout << "\t\t\t##  # #  ##   ######    ##      ##       ##    ##   ## # # ##   ######\n";
		cout << "\t\t\t## #   # ##   ##        ##      ##       ##    ##   ##  #  ##   ##\n";
		cout << "\t\t\t###     ###   ######    ######  #######  ########   ##     ##   ######\n";
		Sleep(2500);
	}
	static void runApp()
	{
		system("Color f4");
		BankName();
		system("cls");
		Welcome();
		system("cls");
		system("Color f4");
		_Filemanager.getAllData();
		loginOptions();
		loginScreen(loginAs());
	}
};