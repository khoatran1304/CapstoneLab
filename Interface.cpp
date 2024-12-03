#include "Interface.h"

#include <iomanip>
#include <iostream>
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

void processReservation(const HikeList& hikeList, MemberList& memberList,
                        Reservations& reservations)
{
  bool done = false;
  int choice;

  while (!done)
  {
    displayMenu();
    cout << "Please make a selection: ";
    cin >> choice;
    cout << "\n";

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
      cout << "Thank you for visiting!\n";
      done = true;
    }

    system("pause");
  }
}

  void chooseByLocation(const HikeList& hikeList, 
    MemberList& memberList, Reservations& reservations)
  {
    hikeList.printAllLocations();

    cout << "\n";
    cout << "Choose a location: ";
    string location;
    cin >> location;

    cout << "\n";
    hikeList.printByLocation(location);
    askToReserve(hikeList, memberList, reservations);
  }

  void chooseByDuration(const HikeList& hikeList, MemberList& memberList,
    Reservations& reservations)
  {
    cout << "\t(days)" << endl;
    hikeList.printByDuration();

    cout << "\n";
    cout << "How many days are you considering? ";

    int days;
    cin >> days;

    cout << "\n";
    hikeList.printByDuration(days);
    askToReserve(hikeList, memberList, reservations);
  }

  void chooseByDifficulty(const HikeList& hikeList, 
    MemberList& memberList,Reservations& reservations)
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

    auto tolowerDifficulty = tolower(difficulty);

    if (tolowerDifficulty == 'e' || tolowerDifficulty == 'm' ||
        tolowerDifficulty == 's')
    {
      cout << "Your choice: " << tolowerDifficulty << "\n";
    }
    else
    {
      cout << "Invalid choice\n";
      return;
    }

    cout << "\n";
    cout << "\t(difficulty level)" << endl;
    hikeList.printByDifficulty(difficulty);
    askToReserve(hikeList, memberList, reservations);
  }

  void chooseByPrice(const HikeList& hikeList, 
    MemberList& memberList, Reservations& reservations)
  {
    hikeList.printByPrice();
    askToReserve(hikeList, memberList, reservations);
  }

  int askIfMember(MemberList & memberList)
  {
    char isMember;
    cout << "Are you a member? (y/n): ";
    cin >> isMember;

    if (tolower(isMember) == 'y')
    {
      int memberID;
      string lastName;

      cout << "\n";
      cout << "Enter your member ID: ";
      cin >> memberID;

      cout << "\n";
      cout << "Enter your last name: ";
      cin >> lastName;

      cout << "\n";
      memberList.printMember(memberID, lastName);
      return memberID;
    }
    else
    {
      return addNewMember(memberList);
    }
  }

  int addNewMember(MemberList & memberList)
  {
    string firstName, lastName;

    cout << "\t Let's add you to the member list! \n";

    cout << "\t\t Enter your first name: ";
    cin >> firstName;

    cout << "\t\t Enter your last name: ";
    cin >> lastName;
    cout << "\n";

    memberList.addMember(firstName, lastName);
    int newID = memberList.getLastID();

    cout << "\t Welcome to the club! " << "\n"
         << "\t\t Your new member ID is: " << newID << "\n";
    return newID;
  }

  void makeReservation(const HikeList& hikeList, 
    MemberList& memberList,Reservations& reservations)
  {
    int memberID = askIfMember(memberList);
    cout << "Which hike would you like to reserve (hike name)? ";
    string hikeName;
    cin.ignore();
    getline(cin, hikeName);

    cout << "\n";

    hikeList.printByHikeName(hikeName);
    int reservationNo = reservations.addReservation(memberID, hikeName);

    cout << "\n"
         << "\t Before proceeding, please make note of your reservation "
            "number. \n"
         << "\t    Reservation #: " << reservationNo << "\n\n"
         << "( *** Will continue to scheduling and payment. *** )\n";

    showAnyKeysToContinue();
  }

  void viewReservation(const HikeList& hikeList, 
    const MemberList& memberList, const Reservations& reservations)
  {
    int reservation;
    cout << "Enter your reservation number: ";
    cin >> reservation;

    reservations.printReservation(reservation, hikeList, memberList);
    showAnyKeysToContinue();
  }

  void cancelReservation(const HikeList& hikeList, 
    MemberList& memberList, Reservations& reservations)
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

  void askToReserve(const HikeList& hikeList, 
    MemberList& memberList,Reservations& reservations)
  {
    char reserve;
    cout << "\n";
    cout << "Would you like to make a reservation? (y/n): ";
    cin >> reserve;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (tolower(reserve) == 'y')
    {
      makeReservation(hikeList, memberList, reservations);
    }
    else if (tolower(reserve) == 'n')
    {
      showAnyKeysToContinue();
    }
  }

  void showAnyKeysToContinue()
  {
    // Not sure if this is what she means in the requirement...
    cout << "\n";
    cout << "Press any key to continue . . .\n";
    cin.get(); // Wait for any keypress
  }