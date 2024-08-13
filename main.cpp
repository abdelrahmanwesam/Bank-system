#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee{
private:
    string name,password;
    int id;
    double salary;
public:
    //Constructors
    Employee(){
    password=id=salary=0;
    }
    Employee(string name,string password,int id,double salary){
    this->name=name;
    this->password=password;
    this->id=id;
    this->salary=salary;
    }

    //Setters
    void setName(string name){
    this->name=name;
    }
    void setPassword(string password){
    this->password=password;
    }
    void setId(int id){
    this->id=id;
    }
    void setSalary(double salary){
    this->salary=salary;
    }

    //Getters
    string getName(){
    return name;
    }
    string getPassword(){
    return password;
    }
    int getId(){
    return id;
    }
    double getSalary(){
    return salary;
    }

};

int main(){

}
