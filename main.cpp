#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Employee:public Person{
private:
    double salary;
public:
    //Constructors
    Employee(){
    password=id=salary=0;
    }
    Employee(string name,string password,int id,double salary){
    this->name=Validate::Valiname(name);
    this->password=Validate::Valipassword(password);
    this->id=id;
    this->salary=Validate::Setsalary(salary);
    }

    //Setters
    void setSalary(double salary){
     this->salary=Validate::Setsalary(salary);
    }

    //Getters
    double getSalary(){
    return salary;
    }

};

int main(){

}
