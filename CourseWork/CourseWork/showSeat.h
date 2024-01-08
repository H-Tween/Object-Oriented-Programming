#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class showSeat
{
public:
	showSeat();
	~showSeat();
	void initialiseFloorPlan();
	int getNumSeats();
	double getSeatSelection();

private:
	void displayFloorPlan(int r, int c);
	void calsulatePrice(double& price);

protected:
	char floorPlan[7][6];
	int numSeats;
	int rNum;
	double price;
};

//constructor

showSeat::showSeat()
{
	for (int r = 0; r < 7; r++)
		for (int c = 0; c < 6; c++)
			floorPlan[r][c] = '0';

			numSeats = 0;
			rNum = 0;
			price = 0;
}

showSeat::~showSeat()
{

}

//initialise theatre floor plan
void showSeat::initialiseFloorPlan()
{
	for (int r = 0; r < 7; r++)
		for (int c = 0; c < 6; c++)
			floorPlan[r][c] = 'A'; // available
}

int showSeat::getNumSeats()
{
	system("CLS");
	cout << "\n~~~~~~~~~~~~~~~~~~~~Select Seats Interactively~~~~~~~~~~~~~~~~~~~~\n" << endl;

	do
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "How many tickets would you like to purchase (Max. 8)?: ";
		cin >> numSeats;
		cout << endl;
	} while (numSeats != 1 && numSeats != 2 && numSeats != 3 && numSeats != 4 && numSeats != 5 && numSeats != 6 && numSeats != 7 && numSeats != 8);
	return numSeats;
}
