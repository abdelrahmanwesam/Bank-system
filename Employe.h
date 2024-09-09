#pragma once

#include <iostream>
#include <string>
#include "Client.h"
#include "Validate.h"
#include <vector>
#include "Parser.h"
#include "Fileshelper.h"


using namespace std;
class Employe :public Person
{
private:
	double salary;
public:
	//Constructors
	Employe() {
		salary = 0;
	}
	Employe(string name, string password, double salary) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(password);
		this->salary = Validate::Setsalary(salary);
		ofstream employee("Employee.txt", ios::app);
		ofstream employe("EmployeeId.txt");
		employee << this->name << "&" << this->password << "&" << Fileshelper::GetId("EmployeeId.txt") << "&" << this->salary << endl;
		int newid = Fileshelper::GetId("EmployeeId.txt");
		this->id = newid;
		Fileshelper::savelast("EmployeeId.txt", newid);

	}
	Employe(string name, string password, int id, double salary) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(password);
		this->salary = Validate::Setsalary(salary);
		this->id = id;
	}
	//Setters
	void setSalary(double salary) {
		this->salary = Validate::Setsalary(salary);
	}

	//Getters
	double getSalary() {
		return salary;
	}
	int getId() {
		return this->id;
	}
	//Methods:
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << Fileshelper::GetId("EmployeeId.txt") << endl << "Salary = " << salary << endl << "Passwrd = " << "***********" << endl;
		int newid = Fileshelper::GetId("EmployeeId.txt");
		Fileshelper::savelast("EmployeeId.txt", newid);
	}
	void CreatClient(string name, string passwrd, double balnce) {
		Client a(name, passwrd, balnce);
		cout << "\nDone\n";
	}
	void showallClient() {
		cout << "\nAll Client !\n";
		ifstream Cliiient("Client.txt");
		cout << Cliiient.rdbuf();
	}
	void RemoveallClient() {
		ofstream Cliient("Client.txt");
		Cliient << "";
		cout << "\nRemoved\n";
	}
	friend ostream& operator<<(ostream& os, const Employe& emplooye) {
		os << "Name: " << emplooye.name << " "
			<< "Password: " << emplooye.password << " "
			<< "ID: " << emplooye.id << " "
			<< "Salary: " << emplooye.salary << "\n\n";
		return os;
	}
	void addClient(Client& client) {
		//Client a(name,passwrd,balnce);
		Parser::SetNewClientFromEmploy(client);
	}
	Client* searchClient(int id) {
		string idsarch;//هنا هحول الرقم الي مبعوت لي string عشان اسرش في الفايل
		idsarch = to_string(id);
		string line;
		ifstream nnn("Client.txt");
		while (getline(nnn, line)) {
			vector<string>C;
			C = Parser::Spliet(line);
			if (C[2] == idsarch) {
				string name, passwrd;
				int id;
				double salary;
				name = C[0];
				passwrd = C[1];
				id = stoi(C[2]);
				salary = stoi(C[3]);
				Client e(name, passwrd, id, salary);
				vector<Client>vc;
				vc.push_back(e);
				Parser::ShowallClint(vc);
			}
		}
		Client* c;
		return c;
	}
	void editClient(int id, string name, string password, double balance) {
		string idsarch;//هنا هحول الرقم الي مبعوت لي string عشان اسرش في الفايل
		idsarch = to_string(id);
		string line;
		ifstream nnn("Client.txt");
		while (getline(nnn, line)) {
			vector<string>C;
			C = Parser::Spliet(line);
			if (C[2] == idsarch) {
				Client e(name, password, id, balance);
				vector<Client>vc;
				vc.push_back(e);
				Parser::c.push_back(e);
			}


		}

	}
	void listClient() {
		Parser::parseToClient();
	}
};



