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
    memberList.addMember("John", "Doe");
    memberList.addMember("Jane", "Smith", 150);
    memberList.addMember("Alice", "Wonderland", 200);
    memberList.addMember("Bob", "Builder");
    memberList.addMember("Charlie", "Brown", 180);
    memberList.addMember("Dorothy", "Gale", 220);
    memberList.addMember("Eve", "Apple", 250);

    cout << "Member 1 details:\n";
    memberList.printMember(111, "Doe");
    cout << "\nMember 2 details:\n";
    memberList.printMember(112, "Smith");
    cout << "\nMember 3 details:\n";
    memberList.printMember(113, "Wonderland");
    cout << "\nMember 4 details:\n";
    memberList.printMember(114, "Builder");
    cout << "\nMember 5 details:\n";
    memberList.printMember(115, "Brown");
    cout << "\nMember 6 details:\n";
    memberList.printMember(116, "Gale");
    cout << "\nMember 7 details:\n";
    memberList.printMember(117, "Apple");

    // Test Case 2: Adding Points to Members
    Member member("Alice", "Wonderland");
    member.addPoints(200);
    cout << "\nMember points: " << member.getPoints() << endl;

    // Test Case 3: Printing All Hike Locations
    HikeList hikeList;
    hikeList.addHike("Yellowstone", "Eagle Peak", 3, 's', 299.99);
    hikeList.addHike("Yosemite", "Half Dome", 2, 'm', 199.99);
    hikeList.addHike("Grand Canyon", "Bright Angel Trail", 4, 's', 399.99);
    hikeList.addHike("Zion", "Angels Landing", 1, 'm', 149.99);
    hikeList.addHike("Rocky Mountain", "Longs Peak", 5, 's', 499.99);
    hikeList.addHike("Acadia", "Precipice Trail", 1, 's', 129.99);
    hikeList.addHike("Glacier", "Highline Trail", 3, 'm', 279.99);
    hikeList.addHike("Olympic", "Hoh River Trail", 2, 'e', 179.99);

    cout << "\nAll hike locations:\n";
    hikeList.printAllLocations();

    // Test Case 4: Printing Hikes by Location
    cout << "\nHikes by location (Yosemite):\n";
    hikeList.printByLocation("Yosemite");

    // Test Case 5: Printing Hikes by Duration
    cout << "\nHikes by duration (3 days):\n";
    hikeList.printByDuration(3);

    // Test Case 6: Printing Hikes by Difficulty
    cout << "\nHikes by difficulty (strenuous):\n";
    hikeList.printByDifficulty('s');

    // Test Case 7: Printing Hikes by Price
    cout << "\nHikes by price:\n";
    hikeList.printByPrice();

    // Test Case 8: Printing Hikes by Name
    cout << "\nDetails for hike 'Eagle Peak':\n";
    hikeList.printByHikeName("Eagle Peak");

    // Test Case 9: Getting the Price of a Hike
    double price = hikeList.getPrice("Half Dome");
    cout << "Price for 'Half Dome': $" << price << endl;

    // Test Case 10: Clearing Lists
    memberList.clearList();
    hikeList.clearList();
    cout << "\nMember list and hike list cleared.\n";

    return 0;
}
