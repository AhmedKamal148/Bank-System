#pragma once
#include "Client.h"
#include "Employee.h"

bool test = true;
class ClientManger
{
public:
	static void printClientMenu()
	{
		system("cls");
		cout << "\t\t\t\t\t\tClient Functions\n";
		cout << "1-Deposit\n";
		cout << "2-Withdraw\n";
		cout << "3-transferTo\n";
		cout << "4-checkBalance\n";
		cout << "5-Display\n";
		cout << "6-Update Password\n";
		cout << "7-Logout\n";
		cout << endl;
	}
	static bool clientOptions(Client *_Client)
	{
		int x = 0;

		cout << "Enter your choise : ";

		cin >> x;

		switch (x)
		{
		case 1:
		{
			system("cls");
			double amount = 1500;
			cout << "Enter Amount To Deposit : ";
			cin >> amount;
			_Client->Deposit(amount);
			break;
		}
		case 2:
		{
			system("cls");
			double amount = 1500;
			cout << "Enter Amount To Withdraw : ";
			cin >> amount;
			_Client->Withdraw(amount);
			break;
		}
		case 3:
		{
			system("cls");
			double amount = 1500;
			Client *otherClient;
			int id = 0;
			cout << "Enter Client Id you want TransferTo : ";
			cin >> id;
			otherClient = _Employee.Search(id);
			cout << "Enter Amount To transferTo : ";
			cin >> amount;
			if (otherClient != NULL)
			{
				_Client->transferTo(amount, *otherClient);
			}
			else
			{
				cout << "\n******************************************\n";
				cout << "The Other Client Not Found In System\n";
				cout << "******************************************\n\n";
			}
			break;
		}
		case 4:
		{
			system("cls");
			_Client->checkBalance();
			break;
		}
		case 5:
		{
			system("cls");
			_Client->Display();
			break;
		}
		case 6:
		{
			system("cls");
			updatePassword(_Client);
			break;
		}
		case 7:
		{
			return true;
		}
		default:
		{
			cout << "\n*************************************\n";
			cout << "Your Choise Not Found In List\n";
			cout << "*************************************\n\n";
			clientOptions(_Client);
		}
		}
		Back(_Client);
	}
	static void Back(Client* _Client)
	{
		system("pause");
		printClientMenu();
		clientOptions(_Client);
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
	static Client* login(int id, string password)
	{
		Client *clientptr=_Employee.Search(id);
		if (clientptr == NULL)
		{
			cout << "\n****************************\n";
			cout << "Incorrect Id Or Password\n";
			cout << "****************************\n\n";
			return NULL;
		}
		else
		{
			if (clientptr->getPassword() == password)
			{
				return clientptr;
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

