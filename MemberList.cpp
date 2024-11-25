/*
	Tired Asians

	Tran, Minh (Team Leader)
	Tran, Tim // member 2
	Nguyen, Huy // member 3 and so on

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures
*/

#include "MemberList.h"

int INITIAL_ID = 111; // Define the variable here

MemberList::MemberList()
{
	memberList = new set<Member>();
}

void MemberList::addMember(const string& firstName, const string& lastName)
{
	Member newMember(firstName, lastName);
	newMember.setID(INITIAL_ID);
	memberList->insert(newMember);
	
	INITIAL_ID++;
}

void MemberList::addMember(const string& firstName, const string& lastName, int points)
{
	Member newMember(firstName, lastName);
	newMember.setID(INITIAL_ID);
	newMember.addPoints(points);
	memberList->insert(newMember);

	INITIAL_ID++;
}

int MemberList::getLastID() const
{
	return INITIAL_ID - 1;
}

int MemberList::getPoints(int memberID) const
{
	auto iter = find_if(
			memberList->begin(),
			memberList->end(),
			[memberID](Member member)
			{ return member.getID() == memberID; });

	if (iter != memberList->end())
	{
		return iter->getPoints();
	}

	return 0; // Should we change to -1 ( this mean undetect the user )
}

void MemberList::printMember(int memberID, const string &lastName) const
{
	auto iter = find_if(memberList->begin(), memberList->end(), [memberID](Member member)
											{ return member.getID() == memberID; });

	if (iter != memberList->end() && iter->getLastName() == lastName)
	{
		iter->printMember();
		cout << "\t" << "Membership # " << memberID << "\n";
	}
}

void MemberList::clearList()
{
	memberList->clear();
}

MemberList::~MemberList()
{
	if (memberList)
	{
		memberList->clear();
		delete memberList;
		memberList = nullptr;
	}
}
