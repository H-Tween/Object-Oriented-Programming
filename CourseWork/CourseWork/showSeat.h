#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class showSeat
{
public:
	showSeat();
	void initialiseFloorPlan();
	int getNumSeats();
	double getSeatSelection(int numSeats);
	void updateFloorPlan();
	void displayFloorPlan();

protected:
	char floorPlan[7][6];
	int numSeats;
	int numOfRows = 7;
	int numOfColumns = 6;
};

//constructor

showSeat::showSeat()
{
	for (int r = 0; r < numOfRows; r++)
		for (int c = 0; c < numOfColumns; c++)
			floorPlan[r][c] = '0';

			numSeats = 0;
}

//initialise theatre floor plan
void showSeat::initialiseFloorPlan()
{
	for (int r = 0; r < numOfRows; r++)
		for (int c = 0; c < numOfColumns; c++)
			floorPlan[r][c] = 'A'; // available
}

int showSeat::getNumSeats()
{
	system("CLS");
	cout << "\n~~~~~~~~~~~~~~~~~~~~Select Seats Interactively~~~~~~~~~~~~~~~~~~~~" << endl;

	displayFloorPlan();

	bool ticketSelectionSuccssful = false;

	do
	{
		//cin.clear();
		//cin.ignore(100, '\n');
		cout << "\nHow many tickets would you like to purchase (Max. 8)?: ";
		cin >> numSeats;
		cout << endl;
		while (numSeats != 1 && numSeats != 2 && numSeats != 3 && numSeats != 4 && numSeats != 5 && numSeats != 6 && numSeats != 7 && numSeats != 8) 
		{
			cout << "\nPlease enter a valid number of tickets:  ";
			cin >> numSeats;
		}
	} while (ticketSelectionSuccssful == true);
	return numSeats;
}

double showSeat::getSeatSelection(int numSeats)
{
	int row;
	int column;
	bool seatSuccessfull = false;
	double newNumberOfSeats = 0;
	for (int i = 0; i < numSeats; i++)
	{
		do
		{
			cout << "\nPlease enter the ROW number of the seat you would like to purchase: ";
			cin >> row;
			while (row != 1 && row != 2 && row != 3 && row != 4 && row != 5 && row != 6 && row != 7)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please select a valid row number: ";
				cin >> row;
			}
			cout << "\nPlease enter the COLUMN number of the seat you would like to purchase: ";
			cin >> column;
			while (column != 1 && column != 2 && column != 3 && column != 4 && column != 5 && column != 6)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please select a valid column number: ";
				cin >> column;
			}
			row = row - 1;
			column = column - 1;
			if (floorPlan[row][column] == 'A')
			{
				floorPlan[row][column] = 'H';
				seatSuccessfull = true;
			}
			else
			{
				cout << "\nSeat is not available";
				seatSuccessfull = false;
			}

		} while (seatSuccessfull == false);

		displayFloorPlan();
		
		newNumberOfSeats = newNumberOfSeats + 1;
	}
	cout << "\nYour sets are successfully on hold, please continue to payment\n";
	return newNumberOfSeats;
}

void showSeat::displayFloorPlan()
{
	cout << "\n";
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfColumns; j++) {
			cout << floorPlan[i][j] << " ";
		}
		cout << endl;
	}
}

void showSeat::updateFloorPlan()
{
	for (int i = 0; i < numOfRows; i++) {
		for (int j = 0; j < numOfColumns; j++) {
			if (floorPlan[i][j] == 'H')
			{
				floorPlan[i][j] = 'S';
			}
		}
	}
	cout << "\nSeating Updated\n";
}