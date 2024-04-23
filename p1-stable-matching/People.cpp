/*
 * @file People.cpp
 * @brief Implementation of the People class methods.
 *
 * This file contains the implementation of the People class, which represents a group of people
 * and their preferences for matching with pets.
 *
 * @author Phat Tran
 * @usage This class is used to model people and their preferences for matching with pets.
 *
 */

#include "People.h"
#include <fstream>
#include <iostream>

/*
 * @brief Constructor for the People class.
 * @pre Valid path to data file provided.
 * @post People object is initialized, data is loaded from the file.
 */
People::People(const string &dataFile) : dataFile(dataFile)
{
    if (!this->loadData())
    {
        cerr << "Failed to get data from file: " << dataFile << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Successfully loaded people data from file: " << dataFile << endl;
}

/*
 * @brief Destructor for the People class.
 * @pre None.
 * @post Clean-up resources, if any.
 */
People::~People() {}

/*
 * @brief Get the total count of people.
 * @pre None.
 * @post Returns the total count of people.
 */
int People::getPeopleCount() const
{
    return this->peopleCount;
}

/*
 * @brief Get the name of a specific person.
 * @pre Valid index for peopleNames vector.
 * @post Returns the name of the person at the specified index.
 */

string People::getPeopleName(int peopleIndex) const
{
    return this->peopleNames[peopleIndex];
}

/*
 * @brief Get the preference value of a person.
 * @pre Valid index for peoplePreferences vector.
 * @post Returns the highest preference value, or -1 if no preference available.
 */
int People::getPeoplePreference(int peopleIndex)
{
    // Check if the given people index is valid and the corresponding pet preference list is not empty
    if (isValidPeopleIndex(peopleIndex) && !(this->peoplePreferences[peopleIndex].empty()))
    {
        int petIndex = this->peoplePreferences[peopleIndex].front();
        this->peoplePreferences[peopleIndex].pop();
        return petIndex;
    }

    return -1;
}

/*
 * @brief Get the index of the pet matched with a person.
 * @pre Valid index for matchedPet vector.
 * @post Returns the index of the matched pet.
 */
int People::getMatchedPet(int peopleIndex) const
{
    return this->matchedPet[peopleIndex];
}

/*
 * @brief Set the index of the pet matched with a person.
 * @pre Valid indices for matchedPet and peoplePreferences vectors.
 * @post Matched pet index is set for the specified person.
 */
void People::setMatchedPet(int peopleIndex, int petIndex)
{
    this->matchedPet[peopleIndex] = petIndex;
}

/*
 * @brief Check if the given index is a valid index for a person.
 * @pre None.
 * @post Returns true if the index is valid, false otherwise.
 */
bool People::isValidPeopleIndex(int peopleIndex) const
{
    return peopleIndex >= 0 && peopleIndex < this->peoplePreferences.size();
}

/*
 * @brief Load data from the specified file to initialize the People object.
 * @pre Valid path to data file provided.
 * @post Returns true if data loading is successful, false otherwise.
 */
bool People::loadData()
{
    ifstream inputFile(dataFile);

    if (!inputFile.is_open())
    {
        return false; // Failed to open the given data file
    }

    // Read the number of people
    inputFile >> this->peopleCount;

    // Read names of people
    for (int i = 0; i < peopleCount; ++i)
    {
        string peopleName;
        inputFile >> peopleName;
        this->peopleNames.push_back(peopleName);
    }

    // Initialize matchedPet with peopleCount size, all set to -1
    matchedPet.assign(peopleCount, -1);

    // Read preference lists of people
    for (int i = 0; i < peopleCount; ++i)
    {
        queue<int> preferences;

        for (int j = 0; j < peopleCount; ++j)
        {
            int preference;
            inputFile >> preference;
            preferences.push(preference);
        }

        this->peoplePreferences.push_back(preferences);
    }

    inputFile.close();
    return true;
}

/*
 * @brief Display data related to the People object.
 * @pre None.
 * @post Data is displayed on the console.
 */
void People::displayData() const
{
    // Display data for testing purposes
    cout << "Names and preference lists of people:" << endl;
    for (int i = 0; i < this->peopleCount; ++i)
    {
        cout << this->peopleNames[i] << ": ";
        queue<int> preferences = this->peoplePreferences[i];
        while (!preferences.empty())
        {
            cout << preferences.front() << " ";
            preferences.pop();
        }
        cout << endl;
    }

    cout << "Matched pets:" << endl;
    for (int i = 0; i < this->peopleCount; ++i)
    {
        cout << this->peopleNames[i] << ": " << this->matchedPet[i] << endl;
    }
}
