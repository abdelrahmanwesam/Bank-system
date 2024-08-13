#include <iostream>
#include <exception>
#include <cctype>
#include <string>
#include <fstream>
using namespace std;
class Client {
	//Data:
	string name, paswrd;
	int id;
	double balance;
public:
	//Cons:
	Client() {
		this->id = 0;
		this->balance = 0;
		this->paswrd = "*************";
	}
	Client(string name, string paswrd, int id,double balance) {
		this->balance = balance;
		this->id = id;
		this->name = name;
		this->paswrd = paswrd;
		ofstream dataclint("Dataclinttt.txt", ios::app);
		dataclint << this->name<< " " << this->paswrd << " " <<this->id << " " << " " << this->balance << endl;
		dataclint.close();
	}
	Client(string name, string paswrd, int id) {
		this->id = id;
		this->name = name;
		this->paswrd = paswrd;
		ofstream dataclint("Dataclinttt.txt", ios::app);
		dataclint << this->name << " " << this->paswrd << " " << this->id << " ";
		dataclint.close();
	}
	Client(string name, string paswrd) {
		this->name = name;
		this->paswrd = paswrd;
		ofstream dataclint("Dataclinttt.txt", ios::app);
		dataclint << this->name << " " << this->paswrd << " ";
		dataclint.close();
	}
	//Setter:
	void Setid(int id){
		this->id = id;
		ofstream dataclint("Dataclinttt.txt", ios::app);
		dataclint <<this->id <<" " ;
		dataclint.close();
	}
	void Setbalnce(double balnce) {
		this->balance = balnce;
		ofstream dataclint("Dataclinttt.txt", ios::app);
		dataclint << this->balance<<endl;
		dataclint.close();
	}
	//Getter:
	string Getname() {
		return name;
	}
	int Getid() {
		return id;
	}
	string GetPasswrd(){
		return paswrd;
	}
	//Methods:
	void Depoist(double b) {
		this->balance = this->balance + b;
	}
	void Transfer(Client& a,double m) {
		if (balance < m) {
			cout << "\nError ! \nYou ara not have this Amount\n\n";
		}
		else {
			a.balance=a.balance+m;
			this->balance = this->balance - m;
		}
	}
	void withdrow(double n) {
		if (n > this->balance) {
			cout << "Error !\nYou ara not have this Amount\n\nYou want deposit a first ?n/y = ";
			char nn;
			cin >> nn;
			if (nn == 'y') {
				double num;
				cout << "    How ? = ";
				cin >> num;
				Depoist(num);
				if (this->balance < n) {
					cout << "\nStill you not have this Amount \nYou want deposit a first ?n/y = ";
					char g;
					cin >> g;
					if (g == 'y') {
						double num2;
						cout << "    How ? = ";
						cin >> num2;
						Depoist(num2);
						if (this->balance >= n) {
							this->balance = this->balance - n;
						}
					}
				}
			}
			else if (n != 'y') {
				cout << "\nOk\n";
			}

		}
	}
	void infodata() {
		cout << "\nName= " << name << endl << "Pas= " << "**********" << endl << "Balance=" << this->balance << endl << "Id= " << id << endl;
	}
	static void creatnewaccount() {
		int count = 0;
		int tp = 1;//ãä åäÇ äÚáã ÇÐÇ ßÇä ÇáãÓÊÎÏã ÇÏÎá ÇßËÑ ãä 8 ÍÑæÝ Çæ ÇÑÞÇã ááÍÓÇÈ ÇáÎÇÕ Èí
		//if (d == 'n') {
			cout << "\n\nOK pleas insert next data ! \n\n";
			string namecli, passwrdcli;
			int id;
			double balnce;
			cout << "\nInsert your name = ";
			cin >> namecli;
			for (int i = 0; i < size(namecli); i++) {
				if (!isalpha(namecli[i])) {
					count++;
				}
			}
			if (count > 0) {
				cout << "\nplease don't insert any number with name\n\nAgain =";
				cin >> namecli;
				count = 0;
			}
			for (int i = 0; i < size(namecli); i++) {
				if (!isalpha(namecli[i])) {
					count++;
				}
			}
			if (count != 0) {
				cout << "\n say you i do not let you insert any num in name \nAgin else time \n";
				return;
			}
			else if (count == 0) {
				cout << "\nInsert your Passwrd = ";
				cin >> passwrdcli;
				if (passwrdcli.size() < 8) {
					cout << "\nPlease enter a password more than 8 letters or numbers = ";
					cin >> passwrdcli;
					tp = 0;
					if (passwrdcli.size() >= 8) {
						tp = 1;
					}
				}
				if (tp == 0) {
					cout << "\n\nError still paswrd low 8 Good luck !\n";
					return;
				}
				if (tp == 1) {
					cout << "\nInsert your Id = ";
					cin >> id;
					cout << "\nHow many you want Debosit in your account ?= ";
					cin >> balnce;
					if (balnce < 1500) {
						cout << "\n\nSorry you should give me 1500 or more ! \n\nDo you have This amount or no ?y/n \n";
						char b;//åäÇÇ ÓæÝ äÚÑÝ ãä ÇáãÓÊÎÏã ãÚå ÇßËÑ ãä 1500Çã áÇ 
						cin >> b;
						if (b == 'y') {
							cout << "\nHow much is available = ";
							cin >> balnce;
						}
						else if (b == 'n') {
							cout << "\n\nGood luck \n";
						}
					}
					if (balnce >= 1500) {
						ofstream dataclint("Dataclinttt.txt", ios::app);
						dataclint << namecli << " " << passwrdcli << " " << id << " " << " " << balnce << endl;
						dataclint.close();
						cout << "\nOk\n\nYou can used this account aftar 2 min ! \n";
					}
				}
			}
	}
};
int main(){
	cout << "\nYou want creat new account in Bank or you has account ? n/h = ";//her will know the user have account or he wants creat new account:
	char d;
	cin >> d;
	if (d == 'n') {
		Client::creatnewaccount();
	}
	else if (d == 'h') {
		/*Client::insertusertoaccount();*/
		int count = 0;
		for (int i = 0; i < 5;) {
			cout << "\nGive me your username and pasward ? \n\n";
			string namecc, pascc;//åäÇ ÈäÎÒä ÇáÇÓã Çáí åäÇÎÏæ ãä ÇáãÓÊÎÏã æäÞÇÑä ÈÇáãÊÎÒä æäÝÓ ÇáßáÇã ÇáÈÇÓæÑÏ 
			string namevali, pasvali;//åäÇ ÈíÊÎÒä ÌãíÚ ÇáÈÇÓæÑÏ æÇáíæÒÑäíã Çáí åäÊÃßÏ Èíåã ãä ÇáãÓÊÎÏã
			cout << "UserName = ";
			cin >> namecc;
			cout << "\nPasswrd = ";
			cin >> pascc;
			int id;
			double balnce;
			ifstream dataclint("Dataclinttt.txt");
			while (dataclint >> namevali >> pasvali)
			{
				if (namevali == namecc && pasvali == pascc) {
					count = 5;
					dataclint >> id >> balnce;
					dataclint.close();
					i = 10;
					break;
				}

			}
			if (count == 5) {
				cout << "\nOk\n";
				cout << "\nWaht you want \n\n";
				Client a(namevali, pasvali, id, balnce);
				cout << "\nYou want show all data for you ? Inseet  s \n";
				cout << "you want transfer / Deposit / withdrow = t/d/w\n";
				cout << " = ";
				char f;
				cin >> f;
				if (f == 's') {
					a.infodata();
				}
				else if (f == 'd') {
					cout << "\nHow much do you want to deposit ? = ";
					double dd;
					cin >> dd;
					a.Depoist(dd);
					cout << "\nDone\nYou have in your Account= " << dd + balnce << endl;
				}
				else if (f == 'w') {
					cout << "\n How much you want to withdrow ? = ";
					double ww;
					cin >> ww;
					a.withdrow(ww);
					cout << "\nDone\nYou have in your Account= " << ww - balnce << endl;
				}


				else if (f == 't') {
					cout << "\n You must go to employee \n";
					//////////////
				}
			}

			else if (count != 5) {
				cout << "\nTry Agien\n";
			}

		}
		
	}

}
	