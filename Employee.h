#pragma once
#include "Validate.h"
#include "Person.h"
#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
	class Employee :public Person {
	private:
		double salary;
	public:
		//Constructors
		Employee() {
			password = id = salary = 0;
		}
		Employee(string name, string password, int id, double salary) {
			this->name = Validate::Valiname(name);
			this->password = Validate::Valipassword(password);
			this->id = id;
			this->salary = Validate::Setsalary(salary);
		}

		//Setters
		void setSalary(double salary) {
			this->salary = Validate::Setsalary(salary);
		}

		//Getters
		double getSalary() {
			return salary;
		}
		void InfoData() {
			cout << "Name = " << name << endl << "Id = " << id << endl << "Salary = " << salary << endl << "Passwrd = " << "***********" << endl;
		}

	};


