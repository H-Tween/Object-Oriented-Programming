#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

class customer
{
public:
	customer();
	void getLogin();
	void getProfileInfo(string &fName, string &sName, string &address);

protected:
	string fName;
	string sName;
	string address;
};

//constructor

customer::customer()
{
	fName = "";
	sName = "";
	address = "";
}

//customer logs in
void customer::getLogin()
{
	string username;
	string password;

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~Log In~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cout << "\n Welcome to the Bucks Centre for the Preforming Arts ticket purchasing system!" << endl;
	cout << "			Please log in." << endl;
	cout << "Enter username: ";
	getline(cin, username);

	while (username.length() > 10)
	{
		cout << "Your username should be no more than 10 charaters long." << endl;
		cout << "please re-enter your username: ";
		getline(cin, username);
	}

	cout << "Enter Password: ";
	getline(cin, password);

	while (password.length() > 10)
	{
		cout << "Your password should be no more than 10 characters long." << endl;
		cout << "Please re-enter your password: ";
		getline(cin, password);
	}
}

void customer::getProfileInfo(string &fName, string &sName, string &address)
{

	cout << "\nEnter your first name: ";
	getline(cin, fName);

	cout << "\nEnter your surname: ";
	getline(cin, sName);

	cout << "\nEnter your address: ";
	getline(cin, address);

}