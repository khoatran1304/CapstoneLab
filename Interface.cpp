#include "Interface.h"
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void displayMenu()
{
  cout << "****************************************\n";
  cout << "            HIKING IN THE US            \n";
  cout << "****************************************\n";
  cout << "1. Browse by location\n";
  cout << "2. Browse by duration\n";
  cout << "3. Browse by difficulty\n";
  cout << "4. Browse by price\n";
  cout << "5. Make reservation\n";
  cout << "6. View reservation\n";
  cout << "7. Cancel reservation\n";
  cout << "8. Exit\n";
}

void processReservation(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  int choice;
  do
  {
    displayMenu();
    cout << "Please make a selection: ";
    cin >> choice; 
    cout << choice << "\n";

    if (choice == 1)
    {
      chooseByLocation(hikeList, memberList, reservations);
    }
    else if (choice == 2)
    {
      chooseByDuration(hikeList, memberList, reservations);
    }
    else if (choice == 3)
    {
      chooseByDifficulty(hikeList, memberList, reservations);
    }
    else if (choice == 4)
    {
      chooseByPrice(hikeList, memberList, reservations);
    }
    else if (choice == 5)
    {
      makeReservation(hikeList, memberList, reservations);
    }
    else if (choice == 6)
    {
      viewReservation(hikeList, memberList, reservations);
    }
    else if (choice == 7)
    {
      cancelReservation(hikeList, memberList, reservations);
    }
    else if (choice == 8)
    {
      cout << "Thank you for visiting!";
    }
    else
    {
      cout << "Invalid selection. Please try again.\n";
    }

    if (choice != 8)
    {
      system("pause");
    }
  } while (choice != 8);
}

void chooseByLocation(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  hikeList.printAllLocations();

  cout << "\n";
  cout << "Choose a location: ";
  string location;
  cin >> location;

  cout << "\n";
  hikeList.printByLocation(location);
  cout << "\n";
  askToReserve(hikeList, memberList, reservations);
}

void chooseByDuration(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  hikeList.printByDuration();
  cout << "Enter number of days: ";
  int days;
  cin >> days;
  hikeList.printByDuration(days);
  askToReserve(hikeList, memberList, reservations);
}

void chooseByDifficulty(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  cout << "Select difficulty level: \n\n";
  cout << "\t e. easy \n";
  cout << "\t m. moderate \n";
  cout << "\t s. strenuous \n";

  char difficulty;
  cin >> difficulty;

  // I try clearing the input here, i dont remember how to do it
  // it prints the char and we don't want it to.
  cin.ignore();

  if (difficulty == 'e' || difficulty == 'm' || difficulty == 's')
  {
    cout << "Your choice: " << difficulty << "\n";
  }
  else
  {
    cout << "Invalid choice\n";
    return;
  }

  cout << "\n";
  cout << "\t(difficulty level)" << endl;
  hikeList.printByDifficulty(difficulty);
  cout << "\n";
  askToReserve(hikeList, memberList, reservations);
}

void chooseByPrice(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  hikeList.printByPrice();
  askToReserve(hikeList, memberList, reservations);
}

int askIfMember(MemberList &memberList)
{
  char isMember;
  cout << "Are you a member? (y/n): ";
  cin >> isMember;

  if (isMember == 'y' || isMember == 'Y')
  {
    int memberID;
    string lastName;
    cout << "Enter your member ID: ";
    cin >> memberID;
    cout << "Enter your last name: ";
    cin >> lastName;
    memberList.printMember(memberID, lastName);
    return memberID;
  }
  else
  {
    return addNewMember(memberList);
  }
}

int addNewMember(MemberList &memberList)
{
  string firstName, lastName;
  cout << "Enter your first name: ";
  cin >> firstName;
  cout << "Enter your last name: ";
  cin >> lastName;
  memberList.addMember(firstName, lastName);
  int newID = memberList.getLastID();
  cout << "Welcome, " << firstName << "! Your new member ID is " << newID << ".\n";
  return newID;
}

void makeReservation(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  int memberID = askIfMember(memberList);
  cout << "Which hike would you like to reserve? ";
  string hikeName;
  cin.ignore();
  getline(cin, hikeName);
  hikeList.printByHikeName(hikeName);
  double price = hikeList.getPrice(hikeName);
  int points = memberList.getPoints(memberID);
  double discountedPrice = price - (points / 100.0);
  cout << "Discounted price using points: $" << fixed << setprecision(2) << discountedPrice << "\n";
  reservations.addReservation(memberID, hikeName);
  cout << "Please make a note of your reservation number. Scheduling and payment will be processed next.\n";
}

void viewReservation(const HikeList &hikeList, const MemberList &memberList, const Reservations &reservations)
{
  int reservation;
  cout << "Enter your reservation number: ";
  cin >> reservation;
  reservations.printReservation(reservation, hikeList, memberList);
}

void cancelReservation(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  int reservation;
  cout << "Enter your reservation number: ";
  cin >> reservation;
  reservations.printReservation(reservation, hikeList, memberList);
  char confirm;
  cout << "Are you sure you want to cancel this reservation? (y/n): ";
  cin >> confirm;
  if (tolower(confirm) == 'y')
  {
    reservations.cancelReservation(reservation);
    cout << "Reservation cancelled.\n";
  }
}

void askToReserve(const HikeList &hikeList, MemberList &memberList, Reservations &reservations)
{
  char reserve;
  cout << "Would you like to make a reservation? (y/n): ";
  cin >> reserve;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  if (tolower(reserve) == 'y')
  {
    makeReservation(hikeList, memberList, reservations);
  }
  else if (tolower(reserve) == 'n')
  {
    // Not sure if this is what she means in the requirement...
    cout << "Press any key to continue . . .\n";
    cin.get(); // Wait for any keypress
  }
}
