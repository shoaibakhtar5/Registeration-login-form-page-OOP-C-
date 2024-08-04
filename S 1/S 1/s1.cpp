#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

class Login {
private:
	string loginID, password , email;

public:
	Login() :loginID(""), password("") , email("") {};

	void setID(string id) {
		loginID = id;
	}

	void setPW(string pw) {
		password = pw;
	}
	void setemail(string mail) {
		email = mail;
	}

	string getID() {
		return loginID;
	}
	string getPW() {
		return password;
	}
	string getemail() {
		return email;
	}
};

void registration(Login log) {
	system("cls");
	string id, pw , email;

	cout << " Enter Login ID: " << endl;
	cin >> id;
	log.setID(id);
	start:
	cout << " Enter a Strong Password: " << endl;
	cin >> pw;
	if (pw.length()>=8) {
		log.setPW(pw);
	}
	else {
		cout << " Enter Minimum 8 Characters! " << endl;
		goto start;
	}

	cout << " Enter Email ID: " << endl;
	cin >> email;
	log.setemail(email);
	ofstream outfile("C:\login.txt" , ios::app);
	if (!outfile) {
		cout << " Error: File Not Found! " << endl;
	}
	else {
		outfile << " " << log.getID() << " : " << log.getPW() << endl << endl;
		cout << " User Registered Successfully! " << endl;
	}
	outfile.close();
	
	Sleep(3000);
}

void login() {
	system("cls");
	string id, pw;
	cout << " Enter Login ID: " << endl;
	cin >> id;

	cout << " Enter Password: " << endl;
	cin >> pw;

	ifstream infile("C:\login.txt");
	if (!infile) {
		cout << " Error: File Can't Open! " << endl;
	}
	else {
		string line;
		bool found = false;
		while (getline(infile, line)) {
			stringstream ss;
			ss << line;

			string userID, userPW;
			char delimiter;
			ss >> userID >> delimiter >> userPW;
			if (id == userID && pw == userPW) {
				found = true;
				cout << " Please wait" ;
				for (int i = 0; i < 3; i++) {
					cout << ".";
					Sleep(800);
				}
				system("cls");
				cout << " Welcome to this Page..." << endl;
			}
		
		}
		if (!found) {

			cout << " Error: Incorrect ID or Password: " << endl;
			
		}
		
	}
	infile.close();
	Sleep(5000);
}
int main() {

	Login log;

	bool exit = false;

	while (!exit) {
		system("cls");
		int val;
		cout << " Welcome to Registration & Login Form." << endl;
		cout << " ********************************" << endl;
		cout << " 1.Register." << endl;
		cout << " 2.Login." << endl;
		cout << " 3.Exit..." << endl;
		cout << " Enter Choice:" << endl;
		cin >> val;
		if (val == 1) {
			registration(log);
		}
		else if (val == 2) {

			login();
		}
		else if (val == 3) {
			system("cls");
			exit = true;
			cout << " Exiting the Page... " << endl;
			Sleep(3000);
		}
		Sleep(3000);
	}

	return 0;
}


