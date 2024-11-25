/*
    Tired Asians

    Tran, Minh (Team Leader)
    Tran, Tim // member 2
    Nguyen, Huy // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#ifndef HIKE_LIST_H
#define HIKE_LIST_H

#include "Hike.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class HikeList
{
public:
    void addHike(const Hike &hike, double price);
    void addHike(const string &location, const string &hikeName, int duration, char difficulty, double price);
    double getPrice(const string &hikeName) const;
    void printAllLocations() const;
    void printByLocation(const string &location) const;
    void printByDuration() const;
    void printByDuration(int days) const;
    void printByDifficulty(char difficulty) const;
    void printByPrice() const;
    void printByHikeName(const string &hikeName) const;
    void clearList();

private:
    multimap<Hike, double> hikeList;
};

#endif
