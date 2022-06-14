#include<iostream>/*
#include "Employee.h"
#include "Admin.h"
#include "Client.h"
#include "FileManager.h"
#include"EmployeeManager.h"
#include "AdminManager.h"*/
#include "Screens.h"
using namespace std;

int main()
{
	Screens::runApp();

	//FileManager f;
	//f.getAllData();

	/*EmployeeManager ff;
	int id = 1;
	string pas = "22223333";
	ff.Login(id,pas);*/

	//AdminManager aa;

	//Admin *A = aa.Login(1,"11110000");
	
	//AdminManager::Back(A);

	/*Employee* e ;

	e->setId(2021);
	e->setName("ahmed");
	e->setPassword("22223333");
	e->setSalary(5000);
	EmployeeManager em;

	em.newClient(e);
*/
	
	//f.updateClientFile();

	//Client c(1, "mohamed", "20211388", 5000);
	//Employee e(2021, "ahmed", "22223333", 5000);
	//Admin a(2022, "mustafa", "11110000", 5000);

	//FileManager manager;
	//manager.getAllClients();

	//Employee em;
	//em.editClient(1, "ahmed", "1234567891", 2550);

	//manager.updateClientFile();
	//em.listClient();


	//manager.addClient(c);
	//manager.addEmployee(e);
	//manager.addAdmin(a);

	//vector<Client> v1=manager.getAllClients();
	//vector<Employee> v2 = manager.getAllEmployees();
	//vector<Admin> v3 = manager.getAllAdmins();

	//manager.removeAllClients();
	//manager.removeAllEmployees();
	//manager.removeAllAdmins();

	//Employee em;
	//Client *client = em.Search(1);
	//cout << client->getName();
	//em.editClient(1, "ahmed11", "1234567891", 2550);
	/*for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i].getId()<< "  " << v1[i].getName() << "  " << v1[i].getPassword() << "  " << v1[i].getBalance() << "\n";
	}
	cout << "\n=============================================================\n";
	for (int i = 0; i < v2.size() ; i++)
	{
		cout << v2[i].getName() << "  " << v2[i].getId() << "  " << v2[i].getSalary() << "  " << v2[i].getPassword() << "\n";
	}
	cout << "\n=============================================================\n";
	for (int i = 0; i < v3.size() ; i++)
	{
		cout << v3[i].getName() << "  " << v3[i].getId() << "  " << v3[i].getSalary() << "  " << v3[i].getPassword() << "\n";
	}
	*/

	/*Employee e(2019,"ahmed","64654",20000);

	Admin a(2021,"mustafa","00000",60000);

	c.Deposit(1000);

	c.Withdraw(50000);

	c.transferTo(500, s);

	c.Display();

	cout << "====================================\n";

	s.Display();

	e.Display();

	a.Display();*/

	return 0;
}