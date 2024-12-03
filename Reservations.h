<<<<<<< Updated upstream
=======
/*
        Tired Asians

        Tran, Minh  (Team Leader)
        Tran, Tim   // member 2
        Nguyen, Huy // member 3

        Fall 2024
        CS A250 - C++ 2

        Outdoor Adventures
*/

>>>>>>> Stashed changes
#ifndef RESERVATIONS_H
#define RESERVATIONS_H

#include "HikeList.h"
#include "MemberList.h"

#include <string>

const int RESERVATION_NUM = 5001;

<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
class Node
{
public:
  Node() : reservationNo(0), memberID(0), prev(nullptr), next(nullptr)
  {
  }
  Node(int member, const std::string& aHike, Node* newPrev, Node* newNext)
      : reservationNo(0), memberID(member), hikeName(aHike), prev(newPrev),
        next(newNext)
  {
  }
  int getReservation() const
  {
    return reservationNo;
  }
  int getMemberID() const
  {
    return memberID;
  }
  const std::string& getHikeName() const
  {
    return hikeName;
  }
  Node* getPrev() const
  {
    return prev;
  }
  Node* getNext() const
  {
    return next;
  }
  void setReservationNo(int reservation)
  {
    reservationNo = reservation;
  }
  void setMemberID(int member)
  {
    memberID = member;
  }
  void setHikeName(const std::string& aHike)
  {
    hikeName = aHike;
  }
  void setPrev(Node* newPrev)
  {
    prev = newPrev;
  }
  void setNext(Node* newNext)
  {
    next = newNext;
  }
  ~Node()
  {
  }

private:
  int reservationNo;
  int memberID;
  std::string hikeName;
  Node* next;
  Node* prev;
};

class Reservations
{
public:
  Reservations() : first(nullptr), last(nullptr), count(0){};

  Reservations(const Reservations& other);

  Reservations& operator=(const Reservations& other);

  int addReservation(int memberID, std::string hikeName);

  void cancelReservation(int reservation);

  void printReservation(int reservation, const HikeList& hikeList,
                        const MemberList& memberList) const;

  void clearList();

  ~Reservations();

private:
  Node* first;
  Node* last;
  int count;

  Node* findReservation(int reservation) const;

  void copyCallingObjIsEmpty(const Reservations& other);

  void copyObjectsSameLength(const Reservations& other);

  void copyCallingObjShorter(const Reservations& other);

  void copyCallingObjLonger(const Reservations& other);
};

#endif