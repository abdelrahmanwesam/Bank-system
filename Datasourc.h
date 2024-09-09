#pragma once

#include <iostream>
#include <string>
#include "Admin.h"



using namespace std;
class Datasourc
{
public:
	virtual	void addClient(Client& c) = 0;
	virtual	void addEmployee(Employe& e) = 0;
	virtual	void addAdmin(Admin& a) = 0;
	virtual void getAllClients() = 0;
	virtual void getAllEmploye() = 0;
	virtual void getAllAdmin() = 0;
	virtual	void removeAllClients() = 0;
	virtual	void removeAllEmpploye() = 0;
	virtual	void removeAllAdmin() = 0;
};



