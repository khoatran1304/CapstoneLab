/*
    Tired Asians

    Tran, Minh (Team Leader)
    Tran, Tim // member 2
    Nguyen, Huy // member 3 and so on

    Fall 2024
    CS A250 - C++ 2

    Outdoor Adventures
*/

#include "HikeList.h"

#include <algorithm>
#include <iomanip> // Include this header for setprecision

using namespace std;

void HikeList::addHike(const Hike &hike, double price)
{
  // ascending order by location ?
  hikeList.insert(make_pair(hike, price));
}

void HikeList::addHike(const string &location, const string &hikeName,
                       int duration, char difficulty, double price)
{
  Hike newHike(location, hikeName, duration, difficulty);
  hikeList.insert(make_pair(newHike, price));
}

double HikeList::getPrice(const string &hikeName) const
{
  // Assumption:
  //     The list is non - empty.
  //     The hike exists in the list.

  auto endIter = hikeList.end();

  auto iter =
      find_if(hikeList.begin(), endIter,
              [hikeName](const pair<Hike, double> current)
              {
                return current.first.getHikeName() == hikeName;
              });

  if (iter != endIter)
  {
    return iter->second;
  }

  return 0;
}

void HikeList::printAllLocations() const
{
  if (hikeList.empty())
  {
    cout << "No hikes available.\n";
    return;
  }

  auto it = hikeList.begin();
  while (it != hikeList.end())
  {
    cout << "\t" << it->first.getLocation() << "\n";
    it = hikeList.upper_bound(it->first);
  }
}

void HikeList::printByLocation(const string &location) const
{
  auto endIter = hikeList.end();
  auto currentIter = hikeList.begin();
  while (currentIter != endIter)
  {
    currentIter =
        find_if(currentIter, endIter,
                [location](const pair<Hike, double> &pair)
                {
                  return pair.first.getLocation() == location;
                });
    if (currentIter != endIter)
    {

      cout << currentIter->first
           << "\t" << "  " << fixed << setprecision(2) << "Price (per person): $ " << currentIter->second << "\n";
      // cout << "\t" << currentIter->first.getHikeName() << "(" << currentIter->first.getLocation() << ")" << endl;
      // cout << "\t Difficulty: " << currentIter->first.getDifficulty() << "\n"
      //      << "\t Duration: " << currentIter->first.getDuration() << " day(s)\n"
      //      << "\t Price (per person): $ " << fixed << setprecision(2) << currentIter->second << "\n\n";

      ++currentIter;
    }
  }
}

void HikeList::printByDuration() const
{
  multimap<int, string> tempMultimap;

  string displayLocation;

  for (const auto &hikePair : hikeList)
  {
    tempMultimap.insert(make_pair(hikePair.first.getDuration(),
                                  hikePair.first.getHikeName() +
                                      ", " +
                                      hikePair.first.getLocation()));
  }

  for (const auto &pair : tempMultimap)
  {
    cout << "\t" << "(" << pair.first << ") " << pair.second << "\n";
  }
}

void HikeList::printByDuration(int days) const
{
  for (const auto &hikePair : hikeList)
  {
    if (hikePair.first.getDuration() == days)
    {
      cout << hikePair.first << "\n";
    }
  }
}

void HikeList::printByDifficulty(char difficulty) const
{
  for (const auto &hikePair : hikeList)
  {
    if (hikePair.first.getDifficulty() == difficulty)
    {
      cout << "\t(" << difficulty << ") " << hikePair.first.getLocation() << "\n";
    }
  }
}

void HikeList::printByPrice() const
{
  multimap<double, pair<string, string>> tempMultimap;

  for (const auto &hikePair : hikeList)
  {
    tempMultimap.emplace(hikePair.second,
                         make_pair(hikePair.first.getLocation(),
                                   hikePair.first.getHikeName()));
  }

  for (const auto &pair : tempMultimap)
  {
    cout << "\t"
         << "$" << setw(8) << right << fixed << setprecision(2)
         << pair.first << " - " << pair.second.first << " ("
         << pair.second.second << ")\n";
  }
}

void HikeList::printByHikeName(const string &hikeName) const
{
  auto iter = find_if(hikeList.begin(), hikeList.end(),
                      [hikeName](const pair<Hike, double> pair)
                      {
                        return pair.first.getHikeName() == hikeName;
                      });

  if (iter != hikeList.end())
  {
    cout << iter->first << "\t" << "  " << "$" << fixed
         << setprecision(2) << iter->second << "\n";
  }
}

void HikeList::clearList() { hikeList.clear(); }
