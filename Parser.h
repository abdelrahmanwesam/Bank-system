#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"




using namespace std;

class Parser
{
public:
    
    static vector<string> split(const string& line) {
        vector<string> result;
        stringstream ss(line);
        string item;
        while (getline(ss, item, ',')) {
            result.push_back(item);
        }
        return result;
    }

   
    static Client parseToClient(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double balance = stod(tokens[3]);
        return Client(id, name, password, balance);
    }

    
    static Employee parseToEmployee(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Employee(id, name, password, salary);
    }

    
    static Admin parseToAdmin(const string& line) {
        vector<string> tokens = split(line);
        int id = stoi(tokens[0]);
        string name = tokens[1];
        string password = tokens[2];
        double salary = stod(tokens[3]);
        return Admin(id, name, password, salary);
    }

   
    static void parseFromFile(const string& filename) {
        ifstream file(filename);
        string line;

        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        while (getline(file, line)) {
            if (line.empty()) continue;

            vector<string> tokens = split(line);

            if (tokens.size() != 4) {
                cerr << "Invalid line format: " << line << endl;
                continue;
            }

          
            if (filename.find("client") != string::npos) {
                Client client = parseToClient(line);
                client.display();
            }
            else if (filename.find("employee") != string::npos) {
                Employee employee = parseToEmployee(line);
                employee.display();
            }
            else if (filename.find("admin") != string::npos) {
                Admin admin = parseToAdmin(line);
                admin.display();
            }
        }

        file.close();
    }
};


