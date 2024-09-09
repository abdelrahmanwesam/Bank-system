#pragma once

#include <iostream>
#include <string>
#include "Datasourc.h"
#include "Parser.h"
using namespace std;
class FileManager :public Datasourc
{
public:
	void removeAllClients() {
		ofstream Cliient("Client.txt");
		Cliient << "";
		cout << "\nRemoved\n";
	}
	void removeAllEmpploye() {
		ofstream employee("Employee.txt");
		employee << "";
		cout << "\nRemoved\n";
	}
	void removeAllAdmin() {
		ofstream Adminfile("Admin.txt");
		Adminfile << "";
		cout << "\nRemoved\n";
	}
	void addEmployee(Employe& e) {
		ofstream employee("Employee.txt", ios::app);
		employee << e.Getname() << "&" << e.Getpasswrd() << "&" << e.getId() << "&" << e.getSalary() << endl;
		Parser::e.push_back(e);
	}
	void addClient(Client& c) {
		ofstream Cliient("Client.txt");
		Cliient << c.Getname() << "&" << c.Getpasswrd() << "&" << c.getId() << "&" << c.Getbalnce() << endl;
		Parser::c.push_back(c);
	}
	void addAdmin(Admin& a) {
		ofstream Adminfile("Admin.txt");
		Adminfile << a.Getname() << "&" << a.Getpasswrd() << "&" << a.getId() << "&" << a.getSalary() << endl;
		Parser::a.push_back(a);
	}
	void getAllClients() {
		cout << "\nAll Client !\n";
		ifstream Cliiient("Client.txt");
		cout << Cliiient.rdbuf();
	}
	void getAllEmploye() {
		ifstream employee("Employee.txt");
		cout << "\nAll Employee \n";
		cout << employee.rdbuf();
	}
	void getAllAdmin() {
		ifstream Adminfile("Admin.txt");
		cout << "\nAll Admin \n";
		cout << Adminfile.rdbuf();
	}
};



