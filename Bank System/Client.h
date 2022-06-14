#pragma once
#include"Person.h"
#include<vector>
class Client : public Person
{
private:
	double balance;
public:
	Client()
	{
		balance = 1500;
	}

	Client(int id, string name, string password, double balance) : Person(id, name, password)
	{
		setBalance(balance);
	}

	bool setBalance(double balance)
	{
		if (Validition::checkBalance(balance))
		{
			this->balance = balance;
			return true;
		}
		else
		{
			cout << "\n*************************************\n";
			cout << "Balance less than 1500\n";
			cout << "*************************************\n\n";
			return false;
		}
	}

	double getBalance()
	{
		return balance;
	}

	void Deposit(double amount)
	{
		balance += amount;
	}

	void Withdraw(double amount)
	{
		if (amount <= balance && (balance - amount) >= 1500)
		{
			balance -= amount;
			cout << "\n********************\n";
			cout << "Process Done!\n";
			cout << "********************\n\n";
		}
		else
		{
			cout << "\n*************************************\n";
			cout << "Amount less than your balance\n";
			cout << "*************************************\n\n";
		}
	}

	void transferTo(double amount, Client& c)
	{
		if (amount <= balance && (balance-amount) >=1500 )
		{
			balance -= amount;
			c.balance += amount;
			cout << "\n********************\n";
			cout << "Process Done!\n";
			cout << "********************\n\n";
		}
		else
		{
			cout << "\n*************************************\n\n";
			cout << "Amount less than your balance\n";
			cout << "*************************************\n\n";
		}
	}

	void checkBalance()
	{
		cout << "Your balance = " << balance << endl;
	}

	void Display()
	{
		Person::Display();
		cout << "Balance : " << balance << endl;
	}
	
};
static vector<Client> All_Client;

static vector<Client>::iterator  ClientIt;