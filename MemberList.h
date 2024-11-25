#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"

#include <string>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class MemberList
{
public:
	MemberList();

	void addMember(const string &firstName, const string &lastName);

	void addMember(const string &firstName, const string &lastName, int points);

	int getLastID() const;

	int getPoints(int memberID) const;

	void printMember(int memberID, const string &lastName) const;

	void clearList();

	~MemberList();

private:
	set<Member> *memberList;
};
#endif
