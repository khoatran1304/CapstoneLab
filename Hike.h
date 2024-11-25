/*
    Tired Asians

    Tran, Minh (Team Leader)
    Tran, Tim // member 2
    Nguyen, Huy // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/
 
#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

using namespace std;

class Hike
{
public:
    Hike(const string &theLocation, const string &theHikeName, int theDuration, char theDifficulty);
    string getLocation() const;
    int getDuration() const;
    char getDifficulty() const;
    string getHikeName() const;
    friend ostream &operator<<(ostream &out, const Hike &aHike);
    bool operator<(const Hike &other) const;

private:
    string location;
    string hikeName;
    int duration;
    char difficulty;
};

#endif
