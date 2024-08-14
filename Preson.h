#pragma once
#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
#include "Validate.h"
class Person
{
protected:
//Data:
	string name,passwrd;
	int id;
//Cons:
public:
	Person(){
		this->id = 0;
		this->passwrd = "***********";
	}
	Person(string name,string passwrd,int id) {
		this->name = Validate::Valiname(name);
		this->passwrd = Validate::Valipasswrd(passwrd);
		this->id = id;
	}
//Setter:
	void Setname(string name) {
		this->name = Validate::Valiname(name);
	}
	void Setpasswrd(string passwr) {
		this->passwrd = Validate::Valipasswrd(passwr);
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
//Infodata:
	void InfoData() {
		cout << "Name = " << name << endl << "Id = " << id << endl << endl << "Passwrd = " << "***********" << endl;
	}

};

