#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

using namespace std;

class Member
{
public:
	Member(string newFirst, string newLast)
			: firstName(newFirst), lastName(newLast), id(0), points(0) {}

	void addPoints(int morePoints);

	void setID(int newID);

	int getID() const;

	string getLastName() const;

	int getPoints() const;

	void printMember() const;

	bool operator<(const Member &other) const;

private:
	int id;
	string firstName;
	string lastName;
	int points;
};
#endif