#pragma once
#include<iostream>
using namespace std;
class Validition
{
public:
	static bool checkName(string n)
	{
		bool test = true;

		if ((n.size() >= 5 && n.size() <= 20))
		{
			for (int i = 0; i < n.size(); i++)
			{
				if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z'))
				{
					test = true;
				}
				else
				{
					test = false;
					break;
				}
			}
		}
		else
		{
			test = false;
		}

		return test;
	}

	static bool checkPassword(string p)
	{

		if ((p.size() >= 8 && p.size() <= 20))
		{
			return true;
		}

		return false;
	}

	static bool checkSalary(double s)
	{
		if (s >= 5000)
		{
			return true;
		}
		return false;
	}

	static bool checkBalance(double b)
	{
		if (b >= 1500)
		{
			return true;
		}

		return false;
	}
};

