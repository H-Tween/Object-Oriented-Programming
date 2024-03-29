#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class show
{
public:
	show();
	void selectShow(string& showName, string& showDate);
	string selectTime(string& showName, string& showDate);
protected:
	string showName;
	string showDate;
	string showTime;
};

//constructor
show::show()
{
	showName = "";
	showDate = "";
	showTime = "";
}

//customer selects upcoming show

void show::selectShow(string& showName, string& showDate)
{
	char ch;
	char terminator;
	system("CLS");
	cout << "\n~~~~~~~~~~~~~~~~~~~~ Select An Upcoming Show~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "1. Star Wars: The Musical (20/05/2013)" << endl;
	cout << "2. Les Miserables (21.05/2013)" << endl;
	cout << "3. The Phantom of the Opera (22/05/2013)\n" << endl;

	cin.clear();
	cin.ignore(100, '\n');

	cout << "Please select a show number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2' && ch != '3')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid show number: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1': showName = "Star Wars: The Musical", showDate = "20/05/2013";
		break;
	case '2': showName = "Les Miserables", showDate = "21.05/2013";
		break;
	case '3': showName = "The Phantom of the Opera", showDate = "22/05/2013";
		break;
		
	}

	this->showName = showName; // enters reference variable into class variable
	this->showDate = showDate;

	cin.get(terminator);
}

//customer selects 1pm/7pm showing

string show::selectTime(string& showName, string& showDate)
{
	char ch;
	char terminator;
	cout << "\nFor the show " << showName << " showing at " << showDate << ", the available viewing times are 1pm or 7pm. Please select which time you want to select by entering either '1' or '7'" << endl;
	cout << "Please enter your number: ";
	cin.get(ch);

	while (ch != '1' && ch != '7')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid show time: ";
		cin.get(ch);
	}

	switch (ch)
	{
	case '1': showTime = "1pm";
		break;
	case '7': showTime = "7pm";
		break;
	}

	cin.get(terminator);
	return showTime;

}
