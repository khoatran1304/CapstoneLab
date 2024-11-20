/*
	Minh Team

	Tran, Minh (Team Leader)
	Lastname, Firstname // member 2
	Lastname, Firstname // member 3 and so on

	Fall 2024
	CS A250 - C++ 2

	Outdoor Adventures - Part A
*/

#include<iostream>

#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike) 
{
    string difficultyDisplay;

    // Map difficulty character to a string representation
    switch (aHike.difficulty) {
    case 'e':
        difficultyDisplay = "easy";
        break;
    case 'm':
        difficultyDisplay = "moderate";
        break;
    case 's':
        difficultyDisplay = "strenuous";
        break;
    default:
        difficultyDisplay = "unknown"; // Handle unexpected values
        break;
    }

    // Format and output the hike details
    out << "\t" << aHike.hikeName << " (" << aHike.location << ")" << "\n"
        << " Difficulty: " << difficultyDisplay << "\n"
        << " Duration: " << aHike.duration << " day(s)" << "\n";

    return out;
}




Hike::Hike(const string& theLocation, const string& theHikeName, int theDuration, char theDifficulty)
	: location(theLocation), hikeName(theHikeName), duration(theDuration), difficulty(theDifficulty)
{
	//more logic
}

string Hike::getLocation() const
{
	return location;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

string Hike::getHikeName() const
{
	return hikeName;
}
