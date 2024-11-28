#include "Reservations.h"

#include <iomanip>

int currentReservationNo = INITIAL_RESERVATION_NO;

int Reservations::addReservation(int memberID, const std::string &hikeName)
{
  Node *newNode = new Node(memberID, hikeName, last, nullptr);
  newNode->setReservationNo(currentReservationNo);

  if (last != nullptr)
  {
    last->setNext(newNode);
  }
  else
  {
    first = newNode;
  }

  last = newNode;
  count++;
  currentReservationNo++;

  return newNode->getReservation();
}

void Reservations::cancelReservation(int reservation)
{
  if (first == nullptr)
  {

    return;
  }

  Node *nodeToDelete = findReservation(reservation);

  if (nodeToDelete == nullptr)
  {
    return;
  }

  if (nodeToDelete->getPrev() != nullptr)
  {
    nodeToDelete->getPrev()->setNext(nodeToDelete->getNext());
  }
  else
  {
    first = nodeToDelete->getNext();
  }

  if (nodeToDelete->getNext() != nullptr)
  {
    nodeToDelete->getNext()->setPrev(nodeToDelete->getPrev());
  }
  else
  {
    last = nodeToDelete->getPrev();
  }

  delete nodeToDelete;
  count--;
}

Node *Reservations::findReservation(int reservation) const
{
  Node *current = first;
  while (current != nullptr)
  {
    if (current->getReservation() == reservation)
    {
      return current;
    }
    current = current->getNext();
  }
  return nullptr;
}

void Reservations::printReservation(int reservation, const HikeList &hikeList, const MemberList &memberList) const
{
  Node *node = findReservation(reservation);
  if (node != nullptr)
  {
    std::string hikeName = node->getHikeName();
    int memberID = node->getMemberID();

    double price = hikeList.getPrice(hikeName);
    int points = memberList.getPoints(memberID);
    double discountedPrice = price - (points / 100.0);

    hikeList.printByHikeName(hikeName);

    std::cout << "\n"
              << "\tDiscounted price using points: $" << std::fixed << std::setprecision(2) << discountedPrice << "\n";
  }
  else
  {
    std::cout << "Reservation not found." << std::endl;
  }
}

int Reservations::printCount() const
{
  return count;
}

void Reservations::clearList()
{
  Node *current = first;
  while (current != nullptr)
  {
    Node *temp = current;
    current = current->getNext();
    delete temp;
  }
  first = last = nullptr;
  count = 0;
  currentReservationNo = INITIAL_RESERVATION_NO;
}

Reservations::~Reservations()
{
  clearList();
}