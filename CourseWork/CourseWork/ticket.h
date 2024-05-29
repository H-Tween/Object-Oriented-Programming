#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class ticket
{
public:
	ticket();
	void setPrice(double numOfTickets);
	void paymentCheck(double totalCost);
	void printTicket(string showName, string showDate, string showTime, int numSeats, string fName, string sName, string address);
protected:
	double totalCost;
	string cardNum;
	string expiryDate;
	int pricePerTicket = 20;
	float discount15 = 0.85;
	float discount10 = 0.9;

};

//constructor
ticket::ticket()
{
	totalCost = 0;
}

//calculate discount cost from total price
void ticket::setPrice(double numOfTickets)
{

	// 15% discount on 3 or more tickets
	if (numOfTickets >= 3)
	{
		totalCost = (pricePerTicket * numOfTickets) * discount15;
		cout << "\n 15% Discount Applied \n";
	}
	else
	{
		totalCost = pricePerTicket * numOfTickets;
	}

	// 10% discount on anything >= 100
	if (totalCost >= 100)
	{
		totalCost = totalCost * discount10;
		cout << "\n 10% Discount Applied \n";
	}

	cout << "\nThe total price of your tickets (including any applicable discount) is " << (char)156 << totalCost << ".\n" << endl;
	paymentCheck(totalCost);
}

void ticket::paymentCheck(double totalCost)
{
	cout << "\n========Payment=======" << endl;
	cout << "\nCost: " << totalCost << endl;

	cout << "\nPlease Enter your card details\n" << endl;
	cout << "Please enter your cards number: ";
	bool doPayment = true;
	int last3Digits;

	do
	{
		cin >> cardNum;
		if (cardNum.length() != 16)
		{
			cout << "Please enter a valid card number: ";
		}
		else
		{
			cout << "Please enter your expiry date: ";
			cin >> expiryDate;
			cout << "Please enter the three digits on the back: ";
			cin >> last3Digits;
			// check if card information is valid (this is a placeholder to show card payment authentication is successful)
			cout << "\nCard Accepted\n";
			doPayment = false;
		}
		

	} while (doPayment == true);

}

//prints ticket using data from derived classes
void ticket::printTicket(string showName, string showDate, string showTime, int numSeats, string fName, string sName, string address)
{
	//system("CLS");
	cout << "\n~~~~~~~~~~~~~~~~~~~~ Your Tickets ~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cout << "==============================================================" << endl;
	cout << "=================== The Bucks Centre for the Performing Arts =============" << endl;
	cout << "================================ Enjoy the show! ================================" << endl;
	cout << "Show: " << showName << endl;
	cout << "Date: " << showDate << endl;
	cout << "Time: " << showTime << endl;
	cout << "==============================================================" << endl;
	cout << "Number of seats: " << numSeats << endl;
	cout << "Total cost: " << (char)156 << totalCost << endl;
	cout << "Ticket purchaser: " << fName << " " << sName << endl;
	cout << "Postal address: " << address << endl;
	cout << "==============================================================" << endl;
	cout << "==============================================================\n\n" << endl;
}
