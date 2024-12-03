/*
    Tired Asians

    Tran, Minh (Team Leader)
    Tran, Tim // member 2
    Nguyen, Huy // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "Hike.h"
#include "HikeList.h"
#include "Member.h"
#include "MemberList.h"
#include "Reservations.h"
#include "Interface.h"

#include <iostream>
#include <cassert>
#include "HikeReader.h"
#include "MemberReader.h"
#include "ReservationReader.h"

using namespace std;

void testDefaultImplementations()
{
  // Test Case 1: Adding Members
  MemberList memberList;
  memberList.addMember("Grandma", "Gatewood", 25876);
  memberList.addMember("Jane", "Smith", 150);
  memberList.addMember("Alice", "Wonderland", 200);
  memberList.addMember("Bob", "Builder");
  memberList.addMember("Charlie", "Brown", 180);
  memberList.addMember("Dorothy", "Gale", 220);
  memberList.addMember("Eve", "Apple", 250);

  cout << "Member 1 details:\n";
  memberList.printMember(111, "Gatewood");
  cout << "\nMember 2 details:\n";
  memberList.printMember(112, "Smith");
  cout << "\nMember 3 details:\n";
  memberList.printMember(113, "Wonderland");

  // Test Case 2: Adding Points to Members
  Member member("Jane", "Smith");
  member.addPoints(350);
  cout << "\nMember points: " << member.getPoints() << endl;

  // Test Case 3: Printing All Hike Locations
  HikeList hikeList;
  hikeList.addHike("Alaska", "Flattop Mountain Trail", 1, 'm', 1280);
  hikeList.addHike("Arizona", "South Kaibab Trail", 6, 'd', 4800);
  hikeList.addHike("Georgia", "Blood Mountain via Appalachian Trail",
                   4, 'm', 1500);
  hikeList.addHike("Maine", "Precipice Trail", 2, 'd', 1000);
  hikeList.addHike("Minnesota", "Oberg Mountain Loop", 2, 'e', 230);
  hikeList.addHike("Montana", "Glacier", 4, 'e', 3990.00);
  hikeList.addHike("Utah", "Arches", 3, 'm', 1488);
  hikeList.addHike("Utah", "Zion", 3, 's', 334);
  hikeList.addHike("Virginia", "Old Rag Mountain Loop", 9, 'd', 2380);
  hikeList.addHike("Washington", "Rattlesnake Ledge Trail", 4, 'm',
                   1160);
  hikeList.addHike("Wyoming", "Cascade Canyon Trail", 9, 'm', 1100);
  hikeList.addHike("California", "Yosemite", 6, 'm', 3099.00);
  hikeList.addHike("California", "Redwood", 2, 'e', 245.00);

  cout << "\nAll hike locations:\n";
  hikeList.printAllLocations();

  cout << "\nHikes by location (California):\n";
  hikeList.printByLocation("California");

  cout << "\nHikes by duration:\n";
  hikeList.printByDuration();

  cout << "\nHikes by duration (3 days):\n";
  hikeList.printByDuration(3);

  cout << "\nHikes by difficulty (easy):\n";
  hikeList.printByDifficulty('e');

  cout << "\nHikes by price:\n";
  hikeList.printByPrice();

  cout << "\nDetails for hike 'Yosemite':\n";
  hikeList.printByHikeName("Yosemite");

  // Test Case 9: Getting the Price of a Hike
  double price = hikeList.getPrice("Zion");
  cout << "\nPrice for 'Zion': $" << price << endl;

  // Test Case 10: Clearing Lists
  memberList.clearList();
  hikeList.clearList();
  hikeList.printAllLocations();
  cout << "\nMember list and hike list cleared.\n";

  memberList.printMember(111, "Gatewood");
  hikeList.printAllLocations();
}

void testReservations()
{
  // Create HikeList and MemberList
  HikeList hikeList;
  MemberList memberList;

  // Add sample hikes to HikeList
  hikeList.addHike("California", "Yosemite", 6, 'M', 3099.00);
  hikeList.addHike("Wyoming", "Yellowstone", 5, 'M', 2599.00);
  hikeList.addHike("Montana", "Glacier", 4, 'H', 2299.00);

  // Add sample members to MemberList
  memberList.addMember("Grandma", "Gatewood", 25800);
  memberList.addMember("Jane", "Smith", 150);
  memberList.addMember("John", "Doe", 300);

  // Create Reservations
  Reservations reservations;

  // Add reservations
  int res1 = reservations.addReservation(111, "Yosemite");
  int res2 = reservations.addReservation(112, "Yellowstone");
  int res3 = reservations.addReservation(113, "Glacier");

  // Test reservation numbers
  assert(res1 == 50001);
  std::cout << "Assertion passed: res1 == 50001\n";
  assert(res2 == 50002);
  std::cout << "Assertion passed: res2 == 50002\n";
  assert(res3 == 50003);
  std::cout << "Assertion passed: res3 == 50003\n";

  // Test printReservation (visually check the output)
  std::cout << "Reservation 1 details:\n";
  reservations.printReservation(res1, hikeList, memberList);

  std::cout << "Reservation 2 details:\n";
  reservations.printReservation(res2, hikeList, memberList);

  std::cout << "Reservation 3 details:\n";
  reservations.printReservation(res3, hikeList, memberList);

  // Test cancelReservation - middle node
  reservations.cancelReservation(res2);
  std::cout << "Cancelled Reservation 2\n";
  std::cout << "Cancelled Reservation 2 details (should be empty):\n";
  reservations.printReservation(res2, hikeList, memberList);

  // Test cancelReservation - first node
  reservations.cancelReservation(res1);
  std::cout << "Cancelled Reservation 1\n";
  std::cout << "Cancelled Reservation 1 details (should be empty):\n";
  reservations.printReservation(res1, hikeList, memberList);

  // Test cancelReservation - last node
  reservations.cancelReservation(res3);
  std::cout << "Cancelled Reservation 3\n";
  std::cout << "Cancelled Reservation 3 details (should be empty):\n";
  reservations.printReservation(res3, hikeList, memberList);

  // Clear list and check count
  reservations.clearList();
  assert(reservations.printCount() == 0);
  std::cout << "Assertion passed: reservations.printCount() == 0\n";

  // Test adding reservations after clearing list
  int res4 = reservations.addReservation(111, "Yosemite");
  int res5 = reservations.addReservation(112, "Yellowstone");
  assert(res4 == 50001);
  std::cout << "Assertion passed: res4 == 50001\n";
  assert(res5 == 50002);
  std::cout << "Assertion passed: res5 == 50002\n";
}

void testInterface() 
{
    HikeList hikeList;
    MemberList memberList;
    Reservations reservations;

    // Populate hikeList with some hikes (you can add more as needed)
    hikeList.addHike("California", "Yosemite", 2, 's', 120.00);
    hikeList.addHike("Wyoming", "Yellowstone", 1, 'e', 60.00);
    hikeList.addHike("Utah", "Zion", 1, 'm', 90.00);
    hikeList.addHike("Arizona", "Grand Canyon", 3, 's', 150.00);
    hikeList.addHike("Colorado", "Rocky Mountains", 1, 'e', 80.00);

    // Populate memberList with some members (you can add more as needed)
    memberList.addMember("John", "Doe", 50);
    memberList.addMember("Jane", "Smith", 120);
    memberList.addMember("Bob", "Brown", 30);

    // Add initial reservations (optional for testing)
    reservations.addReservation(111, "Yosemite");
    reservations.addReservation(112, "Grand Canyon");

    // Run the interface to interact with the user
    processReservation(hikeList, memberList, reservations);
}

void testInterfaceAndDatabase() 
{
    HikeList hikeList;
    MemberList memberList;
    Reservations reservations;

    // Populate hikeList with some hikes (you can add more as needed)
    getHikeData(hikeList);

    // Populate memberList with some members (you can add more as needed)
    getMemberData(memberList);

    // Add initial reservations (optional for testing)
    getReservationsData(reservations);

    // Run the interface to interact with the user
    processReservation(hikeList, memberList, reservations);
}


int main()
{
  // testDefaultImplementations();
  // testReservations();
  //testInterface();
  testInterfaceAndDatabase();

  return 0;
}
