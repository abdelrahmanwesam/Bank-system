// project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype> 

using namespace std;
class Admin {
private:
	int id;
	string name, pass;
	double balance;
	bool validName(string newname) {
		if (newname.length() < 5 || newname.length() > 20) {
			cout << "Invalid name. The name should be between 5 and 20 characters." << endl;
			return false;
		}

		for (char ch : newname) {
			if (!isalpha(ch)) {
				cout << "Error: Name should contain only alphabetic characters." << endl;
				return false;
			}
		}

		return true;
	}
	bool validPass(string newpass) {
		if (newpass.length() < 5 || newpass.length() > 20) {
			cout << "Invalid password. The password should be between 5 and 20 characters." << endl;
			return false;
		}

		return true;
	}
	bool validSalary(int newbalance) {
		if (newbalance <= 4999) {
			cout << "minimum salary is 5000." << endl;
			return false;
		}

		return true;
	}
public:
	Admin() {
		id = balance = 0;
	}
	Admin(int id, string name, string pass, double balance) {
		this->id = id;
		this->name = name;
		this->pass = pass;
		this->balance = balance;
	}
	void setId(int id) {
		this->id = id;
	}
	void setName() {
		string newname;
		bool valid = false;

		while (!valid) {
			cout << " please enter your name(note: the name should be alphabetic chars and min size 5 and max size 20) " << endl;
			getline(cin, newname);

			if (validName(newname)) {
				name = newname;
				valid = true;
			}
			else {
				cout << " Please try again." << endl;

			}
		}
	}


	void setPass() {
		string newpass;
		bool valid = false;

		while (!valid) {
			cout << " please enter your password(note: Password must be with min size 8 and max size 20) " << endl;
			getline(cin, newpass);

			if (validPass(newpass)) {
				pass = newpass;
				valid = true;
			}
			else {
				cout << " Please try again." << endl;

			}
		}
	
	}
	void setBalance() {
		int newbalance;
		bool valid = false;
		
		while (!valid) {
			cout << " please enter your balance" << endl;
			cin >> newbalance;
			if (validSalary(newbalance)) {
				balance = newbalance;
				valid = true;
			}
			else {
				cout << " Please try again." << endl;

			}
		}

	
	}
	string getName() {

		return name;
	}
	string getPass() {

		return pass;
	}
	int getBalance() {

		return balance;
	}
	void DisplayInfo() {
		cout << " Name : " << getName() << endl;
		cout << " Password : " << getPass() << endl;
		cout << " Salary : " << getBalance() << endl;
	}
	

};
int main() {

	Admin a;
	a.setName();
	a.setPass();
	a.setBalance();
	a.DisplayInfo();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
