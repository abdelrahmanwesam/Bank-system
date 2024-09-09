#pragma once

#include <iostream>
#include <string>
#include "Employe.h"

using namespace std;
class Admin :public Employe
{
private:
	double salary;
public:
	//Cons:
	Admin() {
		salary = 0;
	}
	Admin(string name, string password, double salary) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(password);
		this->salary = Validate::Setsalary(salary);
		ofstream ad("Admin.txt", ios::app);

		ofstream id("Adminid.txt");

		ad << name << "&" << password << "&" << Fileshelper::GetId("Adminid.txt") << "&" << salary << endl;
		int newid = Fileshelper::GetId("Adminid.txt");
		Fileshelper::savelast("Adminid.txt", newid);
	}
	Admin(string name, string password, int id, double salary) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(password);
		this->salary = Validate::Setsalary(salary);
		this->id = id;
	}
	//Setter:
	void setSalary(double salary) {
		this->salary = Validate::Setsalary(salary);
	}
	//Getters
	double getSalary() {
		return salary;
	}
	//Methods:
	void InfoData() {
		cout << "Name = " << name << endl << Fileshelper::GetId("Adminid.txt") << endl << "Salary = " << salary << endl << "Passwrd = " << "***********" << endl;
	}
	friend ostream& operator<<(ostream& os, const Admin& admin) {
		os << "Name: " << admin.name << " "
			<< "Password: " << admin.password << " "
			<< "ID: " << admin.id << " "
			<< "Salary: " << admin.salary << "\n\n";
		return os;
	}
	void Showallemployee() {
		ifstream employee("Employee.txt");
		cout << "\nAll Employee \n";
		cout << employee.rdbuf();
	}
	void Removeallemployee() {
		ofstream employee("Employee.txt");
		employee << "";
		cout << "\nRemoved\n";
	}

	void editEmploy(int id, string name, string password, double salary) {
		string idsarch;//هنا هحول الرقم الي مبعوت لي string عشان اسرش في الفايل
		idsarch = to_string(id);
		string line;
		ifstream nnn("Employee.txt");
		while (getline(nnn, line)) {
			vector<string>C;
			C = Parser::Spliet(line);
			if (C[2] == idsarch) {
				Employe e(name, password, id, salary);
				vector<Employe>vc;
				vc.push_back(e);
				Parser::e.push_back(e);
			}


		}

	}
	void addEmployee(Employe& em) {
		Parser::SetNewEmployFromAdmin(em);
	}
	Employe* searchEmployee(int id) {
		string idsarch;//هنا هحول الرقم الي مبعوت لي string عشان اسرش في الفايل
		idsarch = to_string(id);
		string line;
		ifstream nnn("Employee.txt");
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
				Employe e(name, passwrd, id, salary);
				vector<Employe>vc;
				vc.push_back(e);
				Parser::Showallemploye(vc);
			}
		}
		Employe* a;
		return a;
	}
	void listEmployee() {
		Parser::parseToEmployee();
	}
};


