#pragma once

#include <iostream>
#include <string>
#include <cctype>
//#include "Admin.h"
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


