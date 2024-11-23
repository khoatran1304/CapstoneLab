#include "HikeList.h"
#include <iomanip> // Include this header for setprecision
/*
    Minh Team

    Tran, Minh (Team Leader)
    Lastname, Firstname // member 2
    Lastname, Firstname // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures - Part A
*/

#ifndef HIKELIST_H
#define HIKELIST_H

void HikeList::addHike(const Hike& hike, double price)
{
    //ascending order by location ?
    hikeList.insert(make_pair(hike, price));
}

void HikeList::addHike(const string& location, const string& hikeName, int duration, char difficulty, double price)
{
    Hike newHike(location, hikeName, duration, difficulty);
    hikeList.insert(make_pair(newHike, price));
}

double HikeList::getPrice(const string& hikeName) const
{
    //Assumption:
    //    The list is non - empty.
    //    The hike exists in the list.

    auto endIter = hikeList.end();

    auto iter = find_if(hikeList.begin(), endIter, [hikeName](const pair<Hike,double> current) { return current.first.getHikeName() == hikeName; });
    
    if (iter != endIter) 
    {
        return iter->second;
    }

    return 0;
}

void HikeList::printAllLocations() const
{
    //Assumption: The list is non - empty.
    //Output must be as shown below.Use the tab escape sequence(\t) to indent.

    auto endIter = hikeList.end();
    auto currentIter = hikeList.begin();
    while (currentIter != endIter)
    {
        cout << "\t" << currentIter->first.getLocation() << "\n";

        currentIter = hikeList.upper_bound(currentIter->first);
    }
}

void HikeList::printByLocation(const string& location) const
{
    //Assumption:
    //    The list is non - empty.
    //    The location exists in the list.

    auto endIter = hikeList.end();
    auto currentIter = hikeList.begin();

    bool found = true;
    do
    {
        currentIter = find_if(hikeList.begin(), endIter, [location](const pair<Hike, double> pair) { return pair.first.getLocation() == location; });

        if (currentIter == endIter)
        {
            found = false;
        }
        else 
        {
            cout << currentIter->first << " Price (per person):  $ " << currentIter->second << "\n";
        }
    } 
    while (found);
}

void HikeList::printByDuration() const
{
    multimap<int, string> tempMultimap;

    string displayLocation;

    for (const auto& hikePair : hikeList)
    {
        tempMultimap.insert
        (
            make_pair(hikePair.first.getDuration(), 
            hikePair.first.getHikeName() + ", " + hikePair.first.getLocation())
        );
    }

    for (const auto& pair : tempMultimap)
    {
        cout << "\t" << "(" << pair.first  << ") " << pair.second << "\n";
    }
}

void HikeList::printByDuration(int days) const
{
    for (const auto& hikePair : hikeList)
    {
        if (hikePair.first.getDuration() == days)
        {
            cout << hikePair.first << "\n";
        }
    }
}

void HikeList::printByDifficulty(char difficulty) const
{
    for (const auto& hikePair : hikeList)
    {
        if (hikePair.first.getDifficulty() == difficulty)
        {
            cout << "\t" << "(" << difficulty << ") " 
                 << hikePair.first.getHikeName() + ", " + hikePair.first.getLocation();
        }
    }
}

void HikeList::printByPrice() const
{
    multimap<double, pair<string, string>> tempMultimap;

    for (const auto& hikePair : hikeList)
    {
        tempMultimap.emplace
        (
            hikePair.second, 
            make_pair(hikePair.first.getLocation(), hikePair.first.getHikeName())
        );
    }

    for (const auto& pair : tempMultimap)
    {
        cout << "\t" << setw(5) << "$" 
             << fixed << setprecision(2) << pair.first 
             << " - " << pair.second.first << " (" << pair.second.second << ")\n";
    }
}

void HikeList::printByHikeName(const string& hikeName) const
{
   auto iter = find_if
               (
                   hikeList.begin(), 
                   hikeList.end(), 
                   [hikeName](const pair<Hike, double> pair) { return pair.first.getHikeName() == hikeName; }
               );

   if (iter != hikeList.end()) 
   {
       cout << iter->first << " $" << fixed << setprecision(2) << iter->second << "\n";
   }
}

void HikeList::clearList()
{
    hikeList.clear();
}

#endif