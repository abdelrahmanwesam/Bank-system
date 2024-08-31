#pragma once
#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
#include "Parser.h"

using namespace std;
class Validate
{
public:
	static string Valiname(string namee) {
		for (int i = 0; i < 5;) {
			for (int i = 0; i < size(namee); i++) {
				if (!isalpha(namee[i])) {
					cout << "\nPlease don't insert any number with your name\nTry again: ";
					cin >> namee;
					i = 0;
				}
				else if (namee.size() < 5 || namee.size() > 20) {
					cout << "\nYour name must be between 5 and 20 characters: ";
					cin >> namee;
					i = 0;
				}
			}
			i = 10;
			break;
		}
		return namee;
	}
	static string Valipassword(string pas) {
		int count = 0;
		for (int i = 0; i < 5;) {
			if (pas.size() > 20 || pas.size() < 8) {
				if (count == 0) {
					cout << "\nYour password must be between 8 and 20 characters: ";
					cin >> pas;
					i = 0;
					count++;
				}
				else if (pas.size() > 20 || pas.size() < 8) {
					cout << "\n\nTry again: ";
					cin >> pas;
					i = 0;
				}
			}
			else {
				i = 10;
				break;
			}
		}
		return pas;
	}
	static double Valibalnce(double bal) {
		for (int i = 0; i < 5;) {
			char s;
			if (bal < 1500) {
				cout << "\nSorry the minimum balace is 1500 \n\nDo you have this amount or no ?y/n = ";
				cin >> s;
				if (s == 'y') {
					cout << "\n\nEnter your balance again: ";
					cin >> bal;
					if (bal < 1500) {
						cout << "\nErorr\n";
						i = 6;

					}
				}
				else if (s != 'y') {
					cout << "\nGood luck \n";
					i = 6;

				}
			}
			else if (bal >= 1500) {
				return bal;
			}
		}
	}
	static double Setsalary(double s) {
		int count = 0;
		for (int i = 0; i < 5;) {
			if (s < 5000) {
				if (count == 0) {
					cout << "\nSorry the minimum salary is 5000 \n= ";
					cin >> s;
					count++;
				}
				if (s < 5000) {
					cout << "\nTry again: ";
					cin >> s;
					i = 0;
				}
				else if (s >= 5000) {
					return s;
					i = 6;
					break;
				}
			}
			else if (s >= 5000) {
				return s;
				i = 6;
				break;
			}
		}
	}
};
//=================================================================
class Person
{
protected:
	//Data:
	string name, password;
	int id;
	//Cons:
public:
	Person() {
		this->id = 0;
		this->password = "***********";
	}
	Person(int id, string name,string passwrd) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(passwrd);
		this->id = id;
	}
	//Setter:
	void Setname(string name) {
		this->name = Validate::Valiname(name);
	}
	void Setpasswrd(string passwr) {
		this->password = Validate::Valipassword(passwr);
	}
	void Setid(int id) {
		this->id = id;
	}
	//Getter:
	string Getname() {
		return this->name;
	}
	int Getid() {
		return id;
	}
	string Getpasswrd() {
		return password;
	}
	//Infodata:
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << id << endl << endl << "Passwrd = " << "***********" << endl;
	}

};
//===================================================

class Client :public Person
{
	//Data:
	double balnce;
public:
	//Cons:
	Client() {
		this->balnce = 0;
	}
	Client( int id, string name , string password, double balance) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(passwrd);
		this->balnce = Validate::Valibalnce(balnce);
		this->id = id;
	}
	Client(int id, string name, string password ) {
		this->password = Validate::Valipassword(passwrd);
		this->name = Validate::Valiname(name);
		this->id = id;
	}
	//Setter:
	void Setbalnce(double baln) {
		this->balnce = Validate::Valibalnce(baln);
	}
	//Getter:
	double Getbalnce() {
		return balnce;
	}
	//Methids:
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << id << endl << "Balnce = " << balnce << endl << "Passwrd = " << "***********" << endl;
	}
	void Depoist(double b) {
		this->balnce = this->balnce + b;
	}
	void withdraw(double n) {
		if (n > this->balnce) {
			cout << "Error !\nYou don't have this amount: \n\nDo you want to deposit first?n/y = ";
			char nn;
			cin >> nn;
			if (nn == 'y') {
				double num;
				cout << "    How much? ";
				cin >> num;
				Depoist(num);
				if (this->balnce < n) {
					cout << "\nYou still don't have the amount \nDo you want to deposit again?n/y = ";
					char g;
					cin >> g;
					if (g == 'y') {
						double num2;
						cout << "    How much? ";
						cin >> num2;
						Depoist(num2);
						if (this->balnce >= n) {
							this->balnce = this->balnce - n;
						}
					}
				}
			}
			else if (n != 'y') {
				cout << "\nOk\n";
			}

		}
		else if (this->balnce >= n) {
			this->balnce = this->balnce - n;
		}
	}
	void Transfer(Client& a, double m) {
		if (this->balnce < m) {
			cout << "\nError ! \nYou don't have this amount to transfer to ( " << a.Getname() << " ) \n\n";
		}
		else {
			a.balnce = a.balnce + m;
			this->balnce = this->balnce - m;
		}
	}
	void CheckBalance() {
		cout << "\n\nBalnce = " << this->balnce << endl;
	}
};
//============================================================

class Employee :public Person {
private:
	double salary;
public:
	//Constructors
	Employee() {
		password = id = salary = 0;
	}
	Employee(int id, string name, string password, double salary) {
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
//==================================================================
class Admin:public Person {
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
	Admin(string name, string passwrd, int id) {
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

int main() {
	///*Client c("Ahmed", "123abceed", 1500, 123);
	//Employee e("Abdelrahman", "azdf32543", 111, 6000);
	//Admin a("mohamed", "mo200255", 12547, 7000);*/
	//c.Depoist(1000);
	//c.InfoData();
	//cout << "\n======================" << endl;
	//e.InfoData();
	//cout << "\n======================" << endl;
	//a.InfoData();
	//cout << "\n======================" << endl;
	
		Parser::parseFromFile("client.txt");
		Parser::parseFromFile("employee.txt");
		Parser::parseFromFile("admin.txt");

		return 0;
}
