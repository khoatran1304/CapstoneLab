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

using namespace std;

void MemberList::addMember(const string& firstName, 
	const string& lastName)
{
	Member newMember(firstName, lastName);
	if (memberList->size() == 0)
	{
		newMember.setID(INITIAL_MEMBER_ID);
		memberList->insert(newMember);
	}
	else
	{
		int currentSize = memberList->size();
		newMember.setID(INITIAL_MEMBER_ID + currentSize);
		memberList->insert(newMember);
	}
}

void MemberList::addMember(const string& firstName, 
	const string& lastName, int points)
{
	Member newMember(firstName, lastName);
	newMember.addPoints(points);
	if (memberList->size() == 0)
	{
		newMember.setID(INITIAL_MEMBER_ID);
		memberList->insert(newMember);
	}
	else
	{
		int currentSize = memberList->size();
		newMember.setID(INITIAL_MEMBER_ID + currentSize);
		memberList->insert(newMember);
	}
}

int MemberList::getLastID() const 
{ 
	auto lastMember = memberList->rbegin();
	return  (*lastMember).getID();
}

int MemberList::getPoints(int memberID) const
{
	auto iter = find_if(memberList->begin(), memberList->end(),
											[memberID](Member member)
											{
												return member.getID() == memberID;
											});

	if (iter != memberList->end())
	{
		return iter->getPoints();
	}

	return 0; // Should we change to -1 ( this mean undetect the user )
}

void MemberList::printMember(int memberID,
														 const string &lastName) const
{
	auto iter = find_if(memberList->begin(), memberList->end(),
											[memberID](Member member)
											{
												return member.getID() == memberID;
											});

	if (iter != memberList->end() && iter->getLastName() == lastName)
	{
		iter->printMember();
		cout << "\t" << "Membership # " << memberID << "\n";
	}
}

void MemberList::clearList()
{
	if (memberList)
	{
		delete memberList;
		memberList = nullptr;
	}
}

MemberList::~MemberList()
{
	clearList();
}