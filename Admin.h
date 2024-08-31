
#pragma once
#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
#include "Person.h"
#include "Validate.h"



using namespace std;
class Admin :public Person {
private:
	double salary;
public:
	//Cons:
	Admin() {
		salary = 0;
	}
	Admin(int id, string name, string password, double salary) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(password);
		this->id = id;
		this->salary = Validate::Setsalary(salary);
	}
	Admin(int id, string name, string password ) {
		this->password = Validate::Valipassword(passwrd);
		this->name = Validate::Valiname(name);
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
		cout << "Name = " << name << endl << "Id = " << id << endl << "Salary = " << salary << endl << "Passwrd = " << "***********" << endl;
	}



};

