#include "Reservations.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

const string RESERVATIONS_FILE = "reservations_database.txt";

void createReservations(ifstream& infile, Reservations& reservations)
{
	int memberID;
	string hikeName;

	while (!infile.eof())
	{
		infile >> memberID >> hikeName;
		reservations.addReservation(memberID, hikeName);
	}
}

void getReservationsData(Reservations& reservations)
{
	ifstream infile;

	infile.open(RESERVATIONS_FILE);

	if (!infile)
	{
		cerr << RESERVATIONS_FILE << " does not exist." << endl;
		exit(1);
	}

	createReservations(infile, reservations);

	infile.close();
}