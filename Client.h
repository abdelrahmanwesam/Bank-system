#pragma once

#include <iostream>
#include <string>
#include "Person.h"
//#include "Fileshelper.h"
using namespace std;
class Client :public Person
{
	double balnce;
public:
	Client() {
		this->balnce = 0;
	}
	Client(string name, string passwrd, double balnce) {
		this->name = Validate::Valiname(name);
		this->password = Validate::Valipassword(passwrd);
		this->balnce = Validate::Valibalnce(balnce);
		ofstream Client("Client.txt", ios::app);
		Client << this->name << "&" << this->password << "&" << Fileshelper::GetId("clientid.txt") << "&" << this->balnce << endl;
		int newid = Fileshelper::GetId("clientid.txt");
		this->id = newid;
		Fileshelper::savelast("clientid.txt", newid);


	}
	Client(string name, string passwrd, int id, double balnce) {
		this->password = Validate::Valipassword(passwrd);
		this->name = Validate::Valiname(name);
		this->id = id;
		this->balnce = balnce;
	}
	//Setter:
	void Setbalnce(double balnce) {
		this->balnce = Validate::Valibalnce(balnce);
		ofstream Client("Client.txt", ios::app);
		Client << this->balnce << "&" << Fileshelper::GetId("clientid.txt") << endl;
		int newid = Fileshelper::GetId("clientid.txt");
		Fileshelper::savelast("clientid.txt", newid);
	}
	//Getter:
	double Getbalnce() {
		return this->balnce;
	}
	int getId() {
		return this->id;
	}
	//Methods:
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
	void CheckBalanceCLient() {
		cout << "\n\nBalnce = " << this->balnce << endl;
	}
	friend ostream& operator<<(ostream& os, const Client& client) {
		os << "Name: " << client.name << " "
			<< "Password: " << client.password << " "
			<< "ID: " << client.id << " "
			<< "Salary: " << client.balnce << "\n\n";
		return os;
	}
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << Fileshelper::GetId("clientid.txt") << endl << "Passwrd = " << "***********" << endl << "Balnce = " << balnce;
	}

};


