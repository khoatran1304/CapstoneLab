#include "HikeList.h"
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

    auto iter = find_if(hikeList.begin(), endIter, [hikeName](Hike current) { return current.getHikeName() == hikeName; });
    
    return iter->second;
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
        currentIter = find_if(hikeList.begin(), endIter, [location](Hike hike) { return hike.getLocation() == location; });

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

}

void HikeList::printByDuration(int days) const
{
}

void HikeList::printByDifficulty(char difficulty) const
{
}

void HikeList::printByPrice() const
{
}

void HikeList::printByHikeName(const string& hikeName) const
{
}

void HikeList::clearList()
{
}

#endif