#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Person
{
protected:
	//Data:
	string name;
	string password;
	int id;
	//Cons:

public:
	Person() {
		this->id = 0;
		this->password = "***********";
	}
	Person(string name, string passwrd, int id) {
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
	/*int Getid() {
		return id;
	}*/
	string Getpasswrd() {
		return password;
	}
	//Infodata:
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << id << endl << endl << "Passwrd = " << "***********" << endl;
	}

};



