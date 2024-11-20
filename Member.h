#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

class Member
{
public:
	
	Member(std::string newFirst, std::string newLast) 
		: firstName(newFirst),lastName(newLast), id(0), points(0) {}

	void addPoints(int morePoints);
	
	void setID(int newID);

	int getID() const;

	std::string getLastName() const;

	int getPoints() const;

	void printMember() const;

private:
	int id;
	std::string firstName;
	std::string lastName;
	int points;
};


#endif