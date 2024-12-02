/*
  Tired Asians

  Tran, Minh (Team Leader)
  Tran, Tim // member 2
  Nguyen, Huy // member 3 and so on

  Fall 2024
  CS A250 - C++ 2

  Outdoor Adventures
*/

#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>

class Member {
public:
  Member(std::string newFirst, std::string newLast)
      : firstName(newFirst), lastName(newLast), id(0), points(0){}

  void addPoints(int morePoints);
  void setID(int newID);

  int getID() const;
  std::string getLastName() const;
  int getPoints() const;

  void printMember() const;
  bool operator<(const Member& other) const;

private:
  int id;
  std::string firstName;
  std::string lastName;
  int points;
};

#endif
