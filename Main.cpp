#include <iostream>
#include "Member.h"
#include "MemberList.h"
#include "Hike.h"
#include "HikeList.h"

using namespace std;


int main()
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
    hikeList.addHike("Georgia", "Blood Mountain via Appalachian Trail", 4, 'm', 1500);
    hikeList.addHike("Maine", "Precipice Trail", 2, 'd', 1000);
    hikeList.addHike("Minnesota", "Oberg Mountain Loop", 2, 'e', 230);
    hikeList.addHike("Montana", "Glacier", 4, 'e', 3990.00);
    hikeList.addHike("Utah", "Arches", 3, 'm', 1488);
    hikeList.addHike("Utah", "Zion", 3, 's', 334);
    hikeList.addHike("Virginia", "Old Rag Mountain Loop", 9, 'd', 2380);
    hikeList.addHike("Washington", "Rattlesnake Ledge Trail", 4, 'm', 1160);
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
    cout << "\nMember list and hike list cleared.\n";

    return 0;
}

