#pragma once
#include"Parser.h"

class FilesHelper
{
public:
	static void saveLast(string fileName, int id)
	{
		fstream file;
		file.open(fileName, ios::out);
		file << id;
		file.close();
	}
	static int  getLast(string fileName)
	{
		fstream file_id;
		string id;

		file_id.open(fileName, ios::in);
		file_id >> id;

		if (id.size()== 0)
		{
			id = "0";
			file_id.open(fileName, ios::out);
			file_id << "0";
		}

		file_id.close();
		return stoi(id);
	}
	static void saveClient(Client c)
	{
		int id = getLast("client_id.txt");
		fstream cf;
		cf.open("Client.txt", ios::app);
		cf << id + 1 << '|' << c.getName() << '|' << c.getPassword() << '|' << c.getBalance() << '\n';
		cf.close();
		saveLast("client_id.txt", id + 1);
	}
	static void saveEmployee(string fileName, string lastIdFile, Employee e)
	{
		int id = getLast(lastIdFile);
		fstream Employee_File;
		Employee_File.open(fileName, ios::app);
		Employee_File << id + 1 << '|' << e.getName() << '|' << e.getPassword() << '|' << e.getSalary() << '\n';
		Employee_File.close();
		saveLast(lastIdFile, id + 1);
	}
	static void saveAdmin(Admin a)
	{
		int id = getLast("Admin_id.txt");
		fstream af;
		af.open("Admin.txt", ios::app);
		af << id+1 << '|' << a.getName() << '|' << a.getPassword() << '|' << a.getSalary() << '\n';
		af.close();
		saveLast("Admin_id.txt", id + 1);
	}
	static void getClients()
	{

		fstream client_file;
		client_file.open("Client.txt", ios::in);
		string returned_line_from_Client;
		while (getline(client_file, returned_line_from_Client, '\n'))
		{
			All_Client.push_back(Parser::parseToClient(returned_line_from_Client));
		}
		client_file.close();
	}
	static void getEmployees()
	{
		fstream employee_file;
		employee_file.open("Employee.txt", ios::in);
		string returned_line_from_Employee;
		while (getline(employee_file, returned_line_from_Employee, '\n'))
		{
			All_Employee.push_back(Parser::parseToEmployee(returned_line_from_Employee));
		}
		employee_file.close();
	}
	static void getAdmins()
	{
		fstream admin_file;
		admin_file.open("Admin.txt", ios::in);
		string line;
		while (getline(admin_file, line, '\n'))
		{
			All_Admin.push_back(Parser::parseToAdmin(line));
		}
		admin_file.close();
	}
	static void clearFile(string fileName, string lastIdFile)
	{
		fstream clientFile, clientLastId;
		clientFile.open(fileName, ios::out);
		clientLastId.open(lastIdFile, ios::out);
		clientFile.close();
		clientLastId.close();
	}
};