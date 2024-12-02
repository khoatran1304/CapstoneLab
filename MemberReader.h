/*
	Tired Asians

	Tran, Minh  (Team Leader)
	Tran, Tim   // member 2
	Nguyen, Huy // member 3

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "MemberList.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string MEMBERS_FILE = "members_database.txt";

void createMemberList(ifstream& infile, MemberList& memberList)
{
	string lastName, firstName;
	int points;

	while (!infile.eof())
	{
		infile >> lastName >> firstName >> points;
		memberList.addMember(firstName, lastName, points);
	}
}

void getMemberData(MemberList& memberList)
{
	ifstream infile;

	infile.open(MEMBERS_FILE);

	if (!infile)
	{
		cerr << MEMBERS_FILE << " does not exist." << endl;
		exit(1); // terminates program
	}

	createMemberList(infile, memberList);

	infile.close();
}