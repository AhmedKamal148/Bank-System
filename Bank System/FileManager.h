#pragma once
#include<fstream>
#include<sstream>
#include <string>
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager : public DataSourceInterface
{
public:

	void addClient(Client c)
	{
		FilesHelper::saveClient(c);
	}
	void addEmployee(Employee e)
	{
		FilesHelper::saveEmployee("Employee.txt", "Employee_id.txt", e);
	}
	void addAdmin(Admin a)
	{
		FilesHelper::saveAdmin(a);
	}
	void getAllClients()
	{
		FilesHelper::getClients();
	}
	void getAllEmployees()
	{
		FilesHelper::getEmployees();
	}
	void getAllAdmins()
	{
		FilesHelper::getAdmins();
	}
	void removeAllClients()
	{
		FilesHelper::clearFile("Client.txt", "client_id.txt");
	}
	void removeAllEmployees()
	{
		FilesHelper::clearFile("Employee.txt", "Employee_id.txt");
	}
	void removeAllAdmins()
	{
		FilesHelper::clearFile("Admin.txt","Admin_id.txt");
	}
	void getAllData()
	{
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}
	void updateClientFile()
	{
		removeAllClients();

		for (int i=0;i<All_Client.size();i++)
		{
			addClient(All_Client[i]);
		}
	}
	void updateEmployeeFile()
	{
		removeAllEmployees();

		for (int i = 0; i < All_Employee.size(); i++)
		{
			addEmployee(All_Employee[i]);
		}
	}
	void updateAdminFile()
	{
		removeAllAdmins();

		for (int i = 0; i < All_Admin.size(); i++)
		{
			addAdmin(All_Admin[i]);
		}
	}
	void updateAllFiles()
	{
		updateClientFile();
		updateEmployeeFile();
		updateAdminFile();
	}
};
