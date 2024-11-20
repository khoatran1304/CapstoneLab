#include "Member.h"

using namespace std;

void Member::addPoints(int morePoints)
{
	points = points + morePoints;
}

void Member::setID(int newID)
{
	id = newID;
}

int Member::getID() const
{
	return id;
}

string Member::getLastName() const
{
	return lastName;
}

int Member::getPoints() const
{
	return points;
}

void Member::printMember() const
{
	cout << "\t" << lastName << ", " << firstName << "\n"
		 << "\tPoints available: " << points << "\n";
}