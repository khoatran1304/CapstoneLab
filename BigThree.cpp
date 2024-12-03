#include "MemberList.h"
#include "Reservations.h"

#include <iostream>

using namespace std;

MemberList::MemberList(const MemberList& other)
{
  set<Member>* copy = new set<Member>(*other.memberList);
  memberList = copy;
}

MemberList& MemberList::operator=(const MemberList& other)
{
  if (this == &other)
  {
    cerr << "Attempted assignment to itself." << endl;
  }
  else
  {
    memberList = new std::set<Member>(*other.memberList);
  }
  return *this;
}

Reservations::Reservations(const Reservations& other)
    : first(nullptr), last(nullptr), count(0)
{
  if (other.first != nullptr)
  {
    Node* current = other.first;
    while (current != nullptr)
    {
      addReservation(current->getMemberID(), current->getHikeName());
      current = current->getNext();
    }
  }
}

Reservations& Reservations::operator=(const Reservations& other)
{
  if (this == &other)
  {
    cerr << "Attempted assignment to itself." << endl;
  }
  else
  {
    if (other.first == nullptr)
      clearList();

    else if (count == 0)
      copyCallingObjIsEmpty(other);

    else if (count > other.count)
      copyCallingObjLonger(other);

    else if (count < other.count)

      copyCallingObjShorter(other);
    else
      copyObjectsSameLength(other);

    Node* currentNode = other.first;
    while (currentNode != nullptr)
    {
      addReservation(currentNode->getMemberID(), currentNode->getHikeName());
      currentNode = currentNode->getNext();
    }

    return *this;
  }
}

void Reservations::copyCallingObjIsEmpty(const Reservations& other)
{
  Node* current = other.first;
  while (current != nullptr)
  {
    addReservation(current->getMemberID(), current->getHikeName());
    current = current->getNext();
  }
}

void Reservations::copyObjectsSameLength(const Reservations& other)
{
  Node* otherCurrent = other.first;
  Node* current = first;
  while (current != nullptr)
  {
    current->setMemberID(otherCurrent->getMemberID());
    current->setHikeName(otherCurrent->getHikeName());
    current->setReservationNo(otherCurrent->getReservation());
    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
  }
}

void Reservations::copyCallingObjShorter(const Reservations& other)
{
  Node* current = first;
  Node* otherCurrent = other.first;
  while (current != nullptr)
  {
    current->setMemberID(otherCurrent->getMemberID());
    current->setHikeName(otherCurrent->getHikeName());
    current->setReservationNo(otherCurrent->getReservation());
    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
  }

  while (otherCurrent != nullptr)
  {
    addReservation(otherCurrent->getMemberID(), otherCurrent->getHikeName());

    otherCurrent = otherCurrent->getNext();
  }
}

void Reservations::copyCallingObjLonger(const Reservations& other)
{
  Node* current = first;
  Node* otherCurrent = other.first;
  for (int i = 0; i < other.count; i++)
  {
    current->setMemberID(otherCurrent->getMemberID());
    current->setHikeName(otherCurrent->getHikeName());
    current->setReservationNo(otherCurrent->getReservation());

    current = current->getNext();
    otherCurrent = otherCurrent->getNext();
  }

  // Deleting the remaining nodes
  int removedNodeCount = count - other.count;

  while (removedNodeCount > 0)
  {
    Node* deleteNode = last;
    if (last->getPrev() != nullptr)
    {
      last = last->getPrev();
      last->setNext(nullptr);
    }
    else
    {
      first = nullptr;
      last = nullptr;
    }
    delete deleteNode;
    removedNodeCount--;
    count--;
  }
}
