#include "Reservations.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Reservations::addReservation(int memberID, std::string hikeName)
{
	int newReservationNo = RESERVATION_NUM + count;
	if (first == nullptr)
	{
		first = new Node(memberID, hikeName, nullptr, nullptr);
		last = first;
		first->setReservationNo(newReservationNo);
		// Common error: Forgetting to reset pointer last.
	}
	
	else
	{	
		last = new Node(memberID, hikeName, last, nullptr);
		last->setReservationNo(newReservationNo);
		last->getPrev()->setNext(last);
	}
	count++;
	return newReservationNo;
}

void Reservations::cancelReservation(int reservation)
{
	if (count == 1)
	{
		delete first;
		last = nullptr;
	}
	else
	{
		Node* cancelledReservation = findReservation(reservation);
		Node* prevReservation = cancelledReservation->getPrev();
		Node* nextReservation = cancelledReservation->getNext();
		prevReservation->setNext(nextReservation);
		nextReservation->setPrev(prevReservation);
		delete cancelledReservation;
		cancelledReservation = nullptr;
	}
}

void Reservations::printReservation(int reservation,const HikeList& hikeList,
	const MemberList& memberList) const
{
	Node* searchedReservation = findReservation(reservation);
	string hikeName = searchedReservation->getHikeName();
	int memberID = searchedReservation->getMemberID();
	hikeList.printByHikeName(hikeName);

	int memberPoints = memberList.getPoints(memberID);
	double hikePrice = hikeList.getPrice(hikeName);
	double discountedPrice = hikePrice - (memberPoints / 100);
	cout << fixed << setprecision(2) << 
		"\tDiscounted price using points: $" 
		<< discountedPrice << "\n";


}

Node* Reservations::findReservation(int reservation) const
{
	Node* searchedReservation = first;
	bool done = false;
	while (searchedReservation != nullptr && !done)
	{
		if (reservation == searchedReservation->getReservation())
			done = true;
		searchedReservation = searchedReservation->getNext();
	}
	return searchedReservation;
}

void Reservations::clearList()
{
	Node* temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	last = nullptr;
	count = 0;
}

Reservations::~Reservations()
{
	delete first;
	delete last;
	first = nullptr;
	last = nullptr;
}