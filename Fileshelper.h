#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Fileshelper
{
public:
	static void savelast(string filename, int id) {
		ofstream fileId(filename);
		fileId << id;
		fileId.close();
	}
	static int GetId(string filename) {
		int last;
		ifstream fileId(filename);
		fileId >> last;
		return last + 1;
	}
	static void saveClint(Client& d) {
		ofstream Newclint("Client.txt", ios::app);
		Newclint << d.Getname() << "&" << d.Getpasswrd() << "&" << GetId("clientid.txt") << "&" << d.Getbalnce() << endl;
		int newid = GetId("clientid.txt");
		savelast("clientid.txt", newid);
	}
	static void saveEmploye(string filename, string fileid, Employe e) {
		ofstream file(filename);
		ofstream fileid(fileid);
		file << e.Getname() << "&" << e.Getpasswrd() << "&" << e.getSalary() << "&" << GetId(fileid) << endl;
		int newid = GetId(fileid);
		savelast(fileid, newid);
	}
	static void GetClint() {
		Parser::parseToClient();

	}
	static void getEmployees() {
		Parser::parseToEmployee();
	}
	static void getAdmins() {
		Parser::parseToAdmin();
	}
	static void clearFile(string fileName, string lastIdFile) {
		ofstream nn(fileName);
		nn << "";
		nn.close();
		ofstream nnn(lastIdFile);
		nnn << "";
		nnn.close();
	}
};



