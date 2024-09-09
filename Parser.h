#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
class Parser
{
public:
    static vector<Client>c;
    static vector<Employe>e;
    static vector<Admin>a;

    static vector<string> Spliet(string line) {
        string word;
        stringstream ss(line);
        vector<string>d;
        while (getline(ss, word, '&')) {
            d.push_back(word);
        }
        return d;
    }
    static Client parseToClient() {
        ifstream nnn("clientid.txt");
        string line;
        while (getline(nnn, line)) {//هنا بنجيب ال data line by line :
            vector<string>cli;
            cli = Spliet(line);//here i send the line to this funcation so cut:
            string name, passwrd;//هنا بستلم الvector وبخزنو عشان ابني اوبجيكت من نوع كلاينت 
            int id;
            double salary;
            name = cli[0];
            passwrd = cli[1];
            id = stoi(cli[2]);//هنا بستخدم الfuncation عشان تحول ال نص الي رقم
            salary = stoi(cli[3]);
            Client e(name, passwrd, id, salary);//هنا بكريت ابجيكت من كل لاين انا قطعتو 
            Parser::c.push_back(e);
            ShowallClint(c);
        }
        Client c;
        return c;
    }
    static Employe parseToEmployee() {
        ifstream nnn("Employee.txt");
        string line;
        while (getline(nnn, line)) {//هنا بنجيب ال data line by line :
            vector<string>cli;
            cli = Spliet(line);//here i send the line to this funcation so cut:
            string name, passwrd;//هنا بستلم الvector وبخزنو عشان ابني اوبجيكت من نوع كلاينت 
            int id;
            double salary;
            name = cli[0];
            passwrd = cli[1];
            id = stoi(cli[2]);//هنا بستخدم الfuncation عشان تحول ال نص الي رقم
            salary = stoi(cli[3]);
            Employe em(name, passwrd, id, salary);//هنا بكريت ابجيكت من كل لاين انا قطعتو 
            Parser::e.push_back(em);
            Showallemploye(e);

        }
        Employe e;
        return e;
    }
    static Admin parseToAdmin() {
        ifstream nnn("Admin.txt");
        string line;
        while (getline(nnn, line)) {//هنا بنجيب ال data line by line :
            vector<string>cli;
            cli = Spliet(line);//here i send the line to this funcation so cut:
            string name, passwrd;//هنا بستلم الvector وبخزنو عشان ابني اوبجيكت من نوع كلاينت 
            int id;
            double salary;
            name = cli[0];
            passwrd = cli[1];
            id = stoi(cli[2]);//هنا بستخدم الfuncation عشان تحول ال نص الي رقم
            salary = stoi(cli[3]);
            Admin ad(name, passwrd, id, salary);//هنا بكريت ابجيكت من كل لاين انا قطعتو 
            Parser::a.push_back(ad);
            ShowallAdmin(a);
        }
        Admin a;
        return a;
    }
    static void ShowallClint(vector<Client>v) {
        vector<Client>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout << *it;
        }
    }
    static void Showallemploye(vector<Employe>v) {
        vector<Employe>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout << *it;
        }
    }
    static void ShowallAdmin(vector<Admin>v) {
        vector<Admin>::iterator it;
        for (it = v.begin(); it != v.end(); it++) {
            cout << *it;
        }
    }

    static void SetNewClientFromEmploy(Client& client) {
        Parser::c.push_back(client);
    }
    static void SetNewEmployFromAdmin(Employe& employe) {
        Parser::e.push_back(employe);
    }
};


