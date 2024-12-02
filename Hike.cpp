/*
    Tired Asians

    Tran, Minh  (Team Leader)
    Tran, Tim   // member 2
    Nguyen, Huy // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "Hike.h"

#include <iostream>
#include <cctype>

using namespace std;

ostream &operator<<(ostream &out, const Hike &aHike)
{
  string difficultyDisplay;

  // Map difficulty character to a string representation
  switch (tolower(aHike.difficulty))
  {
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
  out << "\t" << aHike.hikeName << " (" << aHike.location << ")"
      << "\n"
      << "\t" << "  Difficulty: " << difficultyDisplay << "\n"
      << "\t" << "  Duration: " << aHike.duration << " day(s)"
      << "\n";

  return out;
}

string Hike::getLocation() const { return location; }

int Hike::getDuration() const { return duration; }

char Hike::getDifficulty() const { return difficulty; }

string Hike::getHikeName() const { return hikeName; }

bool Hike::operator<(const Hike &other) const
{
  return location < other.location;
}