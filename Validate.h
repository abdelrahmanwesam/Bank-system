#pragma once
#include <iostream>
#include <exception>
#include <string>
#include <fstream>
using namespace std;
class Validate
{
public:
static string Valiname(string namee){
		for (int i = 0; i < 5;) {
			for (int i = 0; i < size(namee); i++) {
				if (!isalpha(namee[i])) {
					cout << "\nplease don't insert any number with name\nTry agine = ";
					cin >> namee;
					i = 0;
				}
				else if (namee.size() < 5 || namee.size() > 20) {
					cout << "\nnot insert a most of 20 and minima 5 = ";
					cin >> namee;
					i = 0;
				}
			}
			i = 10;
			break;
		}
		return namee;
    }
static string Valipasswrd(string pas) {
	int count = 0;
	for (int i = 0; i < 5;) {
		if (pas.size() > 20 || pas.size() < 5) {
			if (count == 0) {
				cout << "\nnot insert passwrd a most of 20 and minima 5 ! = ";
				cin >> pas;
				i = 0;
				count++;
			}
			else if (pas.size() > 20 || pas.size() < 5) {
				cout << "\n\nTry agine = ";
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
static double Valibalnce(double bal){
	for (int i = 0; i < 5;) {
		char s;
		if (bal < 1500) {
			cout << "\nSorry you should give me 1500 or more ! \n\nDo you have This amount or no ?y/n = ";
			cin >> s;
			if (s == 'y') {
				cout << "\n\nHow much is available =  ";
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
				cout << "\nSorry you should set salary 5000 or more ! \n= ";
				cin >> s;
				count++;
			}
			if (s < 1500) {
				cout << "\nAgine = ";
				cin >> s;
				i = 0;
			}
			else if (s >= 5000) {
				return s;
				i = 6;
				break;
			}
		}
		else if (s >= 1500) {
			return s;
			i = 6;
			break;
		}
	}
}
};

