/*
 * @file People.h
 * @brief Declaration of the People class representing a group of people and their preferences for matching with pets.
 *
 * This file contains the declaration of the People class, which represents a group of people and their preferences
 * for matching with pets. It includes the constructor, destructor, and various member functions for accessing and
 * manipulating people data.
 *
 * @author Phat Tran
 * @usage To use the People class, create an instance by providing the path to the data file. After initialization,
 * you can retrieve information about people, their preferences, and matched pets using various member functions.
 * Example:
 * ```
 * string dataFile = "data.txt";
 * People people(dataFile);
 * int peopleCount = people.getPeopleCount();
 * string personName = people.getPeopleName(0);
 * int preference = people.getPeoplePreference(0);
 * // ...
 * ```
 */

#pragma once

#include <vector>
#include <queue>
#include <string>

using namespace std;

/*
 * @brief Class representing a group of people and their preferences for matching with pets.
 */
class People
{
public:
    /*
     * @brief Constructor for People class.
     * @param dataFile The file containing data to initialize the People object.
     */
    People(const string &dataFile);

    /*
     * @brief Destructor for People class.
     */
    ~People();

    /*
     * @brief Get the total count of people.
     * @return The total count of people.
     */
    int getPeopleCount() const;

    /*
     * @brief Get the name of a specific person.
     * @param peopleIndex Index of the person.
     * @return The name of the person.
     */
    string getPeopleName(int peopleIndex) const;

    /*
     * @brief Get the highest preference value of a person.
     * @param peopleIndex Index of the person.
     * @return The preference value.
     */
    int getPeoplePreference(int peopleIndex);

    /*
     * @brief Get the index of the pet matched with a person.
     * @param peopleIndex Index of the person.
     * @return The index of the matched pet.
     */
    int getMatchedPet(int peopleIndex) const;

    /*
     * @brief Set the index of the pet matched with a person.
     * @param peopleIndex Index of the person.
     * @param petIndex Index of the matched pet.
     */
    void setMatchedPet(int peopleIndex, int petIndex);

    /*
     * @brief Check if the given index is a valid index for a person.
     * @param peopleIndex Index to be checked.
     * @return True if the index is valid, false otherwise.
     */
    bool isValidPeopleIndex(int peopleIndex) const;

    /*
     * @brief Display data related to the People object.
     */
    void displayData() const;

private:
    string dataFile;                      // File containing data to initialize the People object.
    int peopleCount;                      // Total count of people.
    vector<string> peopleNames;           // Names of people.
    vector<queue<int>> peoplePreferences; // Preferences of people for matching with pets.
    vector<int> matchedPet;               // Indices of matched pets.

    /*
     * @brief Load data from the specified file to initialize the People object.
     * @return True if data loading is successful, false otherwise.
     */
    bool loadData();
};
