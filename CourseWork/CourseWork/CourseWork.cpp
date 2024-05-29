#include <iostream>
#include <string>
#include "ticket.h"
#include "customer.h"
#include "show.h"
#include "showSeat.h"

int main()
{
	//variables

	string a, b, c, f, g, h;
	int d;
	double e;
	char ch, terminator;
	
	//objects
	showSeat SEAT;
	customer CUST;
	show SHOW;
	ticket TICK;

	//customer info
	CUST.getLogin();
	CUST.getProfileInfo(f, g, h);

	//display

	system("CLS");

	cout << "\n~~~~~~~~~~~~~~~~~~~~ Main Menu ~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "1. Buy tickets for upcoming shows" << endl;
	cout << "2. Log out\n" << endl;
	cout << "Please enter a menu choice number: ";
	cin.get(ch);

	while (ch != '1' && ch != '2')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Please select a valid menu choice number: ";
		cin.get(ch);
	}

	if (ch == '2')
	{
		return EXIT_SUCCESS;
	}

	do
	{
		SHOW.selectShow(a, b);
		c = SHOW.selectTime(a, b);

		do
		{
			cout << "\nAre you happy with your choice (Y/N)?: ";
			cin.get(ch);
		} while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
		cin.get(terminator);

	} while (ch == 'N' || ch == 'n');

	// deals with selecting seat
	SEAT.initialiseFloorPlan();
	d = SEAT.getNumSeats();
	e = SEAT.getSeatSelection(d); 
	TICK.setPrice(e);
	SEAT.updateFloorPlan();
	TICK.printTicket(a, b, c, d, f, g, h);

	cout << "Updated Floor Plan \n";
	SEAT.displayFloorPlan();

}
