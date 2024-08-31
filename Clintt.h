#pragma once
#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
#include "Validate.h"
#include "Preson.h"
using namespace std;
class Client:public Person
{
//Data:
	double balnce;
public:
	//Cons:
	Client() {
		this->balnce = 0;
	}
	Client(string name, string passwrd,double balnce,int id) {
		this->name = Validate::Valiname(name);
		this->passwrd = Validate::Valipasswrd(passwrd);
		this->balnce = Validate::Valibalnce(balnce);
		this->id = id;
	}
	Client(string name, string passwrd,int id) {
		this->passwrd = Validate::Valipasswrd(passwrd);
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
	void withdrow(double n) {
		if (n > this->balnce) {
			cout << "Error !\nYou ara not have this Amount\n\nYou want deposit a first ?n/y = ";
			char nn;
			cin >> nn;
			if (nn == 'y') {
				double num;
				cout << "    How ? = ";
				cin >> num;
				Depoist(num);
				if (this->balnce < n) {
					cout << "\nStill you not have this Amount \nYou want deposit a first ?n/y = ";
					char g;
					cin >> g;
					if (g == 'y') {
						double num2;
						cout << "    How ? = ";
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
			cout << "\nError ! \nYou ara not have this Amount so transfer this amount for ( " << a.Getname() << " ) \n\n";
		}
		else {
			a.balnce = a.balnce + m;
			this->balnce = this->balnce - m;
		}
	}
	void CheckBalance(){
		cout << "\n\nBalnce = " << this->balnce<<endl;
	}
};



