/*
    Tired Asians

    Tran, Minh  (Team Leader)
    Tran, Tim   // member 2
    Nguyen, Huy // member 3

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "Member.h"

using namespace std;

void Member::addPoints(int morePoints)
{
  points = points + morePoints;
}

void Member::setID(int newID) { id = newID; }

int Member::getID() const { return id; }

string Member::getLastName() const { return lastName; }

int Member::getPoints() const { return points; }

void Member::printMember() const
{
  cout << "\t" << lastName << ", " << firstName << "\n"
       << "\t" << "Points available: " << points << "\n";
}

bool Member::operator<(const Member &other) const
{
  return id < other.id;
}
