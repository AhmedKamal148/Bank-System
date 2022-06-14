#pragma once
#include<iostream>
#include<string>
#include"Validition.h"
using namespace std;

class Person
{
private:
	int id;
	string name, password;
public:
	Person()
	{
		id = 0;
		name = "No-Name";
		password = "No-Password";
	}

	Person(int id, string name, string password)
	{
		setId(id);
		setName(name);
		setPassword(password);
	}

	void setId(int id)
	{
		this->id = id;
	}

	bool setName(string name)
	{
		if (Validition::checkName(name))
		{
			this->name = name;
			return true;
		}
		else
		{
			cout << "Invalid name\n";
			return false;
		}
	}

	bool setPassword(string password)
	{
		if (Validition::checkPassword(password))
		{
			this->password = password;
			return true;
		}
		else
		{
			if (password.size() < 8)
			{
				cout << "Password less than 8\n";
			}
			else if (password.size() > 20)
			{
				cout << "Password greater than 20\n";
			}
			return false;
		}
	}

	int getId()
	{
		return id;
	}

	string getName()
	{
		return name;
	}

	string getPassword()
	{
		return password;
	}

	void Display()
	{
		cout << "id : " << id << "\n";
		cout << "Name : " << name << "\n";
		cout << "Password : " << password << "\n";
	}
};


