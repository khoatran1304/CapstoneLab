/*
    Tired Asians

    Tran, Minh  (Team Leader)
    Tran, Tim   // member 2
    Nguyen, Huy // member 3

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "Member.h"
#include <algorithm>
#include <iostream>
#include <set>
#include <string>

const int INITIAL_MEMBER_ID = 111;

class MemberList
{
public:
  MemberList() { memberList = new std::set<Member>(); }

  void addMember(const std::string &firstName,
                 const std::string &lastName);
  void addMember(const std::string &firstName,
                 const std::string &lastName, int points);

  int getLastID() const;
  int getPoints(int memberID) const;
  void printMember(int memberID, const std::string &lastName) const;

  void clearList();

  ~MemberList();

private:
  std::set<Member> *memberList;
};

#endif
