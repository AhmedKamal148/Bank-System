#pragma once
#include<vector>
#include<string>
#include<sstream>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"

using namespace std;

class Parser
{
public:

	static vector<string> split(string returned_line_from_file)
	{
		vector<string>string_splited;
		string part;
		stringstream lines(returned_line_from_file);

		while (getline(lines, part, '|'))
		{
			string_splited.push_back(part);
		}
		return string_splited;
	}
	static Client parseToClient(string returned_line_from_Client)
	{
		vector<string> returned_line_parts = split(returned_line_from_Client);
		Client _Client(stoi(returned_line_parts[0]), returned_line_parts[1], returned_line_parts[2], stod(returned_line_parts[3]));
		return _Client;
	}
	static Employee parseToEmployee(string returned_line_from_Employee)
	{
		vector<string> returned_line_parts = split(returned_line_from_Employee);
		Employee _Employee(stoi(returned_line_parts[0]), returned_line_parts[1], returned_line_parts[2], stod(returned_line_parts[3]));
		return _Employee;
	}
	static Admin parseToAdmin(string returned_line_from_Admin)
	{
		vector<string> returned_line_parts = split(returned_line_from_Admin);
		Admin _Admin(stoi(returned_line_parts[0]), returned_line_parts[1], returned_line_parts[2], stod(returned_line_parts[3]));
		return _Admin;
	}
};