/*
 * @file Pet.cpp
 * @brief Implementation of the Pet class methods.
 *
 * This file contains the implementation of the Pet class, which represents a group of pets
 * and their preferences for matching with people.
 *
 * @author Phat Tran
 * @usage This class is used to model pets and their preferences for matching with people.
 *
 */
#include "Pet.h"
#include <fstream>
#include <iostream>

/*
 * @brief Constructor for the Pet class.
 * @pre Valid path to data file provided.
 * @post Pet object is initialized, data is loaded from the file.
 */
Pet::Pet(const string &dataFile) : dataFile(dataFile)
{
    if (!this->loadData())
    {
        cerr << "Failed to get data from file: " << dataFile << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Successfully loaded pets data from file: " << dataFile << endl;
}

/*
 * @brief Destructor for the Pet class.
 * @pre None.
 * @post Clean-up resources, if any.
 */
Pet::~Pet()
{
}

/*
 * @brief Get the total count of pets.
 * @pre None.
 * @post Returns the total count of pets.
 */
int Pet::getPetCount() const
{
    return this->petCount;
}

/*
 * @brief Get the name of a specific pet.
 * @pre Valid index for petNames vector.
 * @post Returns the name of the pet at the specified index.
 */
string Pet::getPetName(int petIndex) const
{
    return this->petNames[petIndex];
}

/*
 * @brief Get the index of the person matched with a pet.
 * @pre Valid index for matchedPeople vector.
 * @post Returns the index of the matched person.
 */
int Pet::getMatchedPerson(int petIndex) const
{
    return this->matchedPeople[petIndex];
}

/*
 * @brief Set the index of the person matched with a pet.
 * @pre Valid indices for matchedPeople vector.
 * @post Matched person index is set for the specified pet.
 */
void Pet::setMatchedPerson(int petIndex, int personIndex)
{
    this->matchedPeople[petIndex] = personIndex;
}

/*
 * @brief Compare the preference rank of a pet for a person.
 * @pre Valid indices for petPreferenceRanks and matchedPeople vectors.
 * @post Returns true if the specified pet prefers the proposed person, false otherwise.
 */
bool Pet::comparePetPreferenceRank(int petIndex, int proposedPersonIndex) const
{
    if (this->petPreferenceRanks[petIndex][proposedPersonIndex] <
        this->petPreferenceRanks[petIndex][getMatchedPerson(petIndex)])
        return true;

    return false;
}

/*
 * @brief Load data from the specified file to initialize the Pet object.
 * @pre Valid path to data file provided.
 * @post Returns true if data loading is successful, false otherwise.
 */
bool Pet::loadData()
{
    ifstream inputFile(dataFile);

    if (!inputFile.is_open())
    {
        return false; // Failed to open the given data file
    }

    // Read the number of pets
    inputFile >> this->petCount;

    // Skip names and preference lists of people
    for (int i = 0; i < petCount * 2 + 1; i++)
    {
        string skipLine;
        getline(inputFile, skipLine);
    }

    // Initialize matchedPeople with petCount size, all set to -1
    this->matchedPeople.assign(petCount, -1);

    // Read names of pets
    for (int i = 0; i < petCount; i++)
    {
        string petName;
        inputFile >> petName;
        this->petNames.push_back(petName);
    }

    // Read preference lists of pets
    for (int i = 0; i < petCount; i++)
    {
        int rank = 1;
        vector<int> petPreferenceList;               // Preference lists of pets
        vector<int> petPreferenceRankList(petCount); // Preference rank list of each pet

        for (int j = 0; j < petCount; j++)
        {
            int preference;
            inputFile >> preference;
            petPreferenceList.push_back(preference);

            // Make a preference rank list
            petPreferenceRankList[preference - 1] = rank;
            rank++;
        }

        this->petPreferences.push_back(petPreferenceList);
        this->petPreferenceRanks.push_back(petPreferenceRankList);
    }

    inputFile.close();
    return true;
}

/*
 * @brief Display data related to the Pet object.
 * @pre None.
 * @post Data is displayed on the console.
 */
void Pet::displayData() const
{
    // Display data for testing purposes
    cout << "Names and preference lists of pets:" << endl;
    for (int i = 0; i < this->petCount; i++)
    {
        cout << this->petNames[i] << ": ";
        for (int j = 0; j < this->petCount; j++)
        {
            cout << this->petPreferenceRanks[i][j] << " ";
        }
        cout << endl;
    }
}
