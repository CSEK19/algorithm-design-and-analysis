/*
 * @file Pet.h
 * @brief Declaration of the Pet class representing a group of pets and their preferences for matching with people.
 *
 * This file contains the declaration of the Pet class, which represents a group of pets and their preferences
 * for matching with people. It includes the constructor, destructor, and various member functions for accessing and
 * manipulating pet data.
 *
 * @author Phat Tran
 * @usage To use the Pet class, create an instance by providing the path to the data file. After initialization,
 * you can retrieve information about pets, their preferences, and matched people using various member functions.
 * Example:
 * ```
 * string dataFile = "data.txt";
 * Pet pets(dataFile);
 * int petCount = pets.getPetCount();
 * string petName = pets.getPetName(0);
 * int matchedPersonIndex = pets.getMatchedPerson(0);
 * // ...
 * ```
 * Additionally, you can compare the preference rank of a pet for a proposed person using the
 * comparePetPreferenceRank function.
 * ```
 * bool prefersProposedPerson = pets.comparePetPreferenceRank(0, 1);
 * if (prefersProposedPerson) {
 *     // Pet 0 prefers the proposed person over its current match.
 * }
 * ```
 */

#pragma once

#include <vector>
#include <string>

using namespace std;

/*
 * @brief Class representing a group of pets and their preferences for matching with people.
 */
class Pet
{
public:
    /*
     * @brief Constructor for Pet class.
     * @param dataFile The file containing data to initialize the Pet object.
     */
    Pet(const string &dataFile);

    /*
     * @brief Destructor for Pet class.
     */
    ~Pet();

    /*
     * @brief Get the total count of pets.
     * @return The total count of pets.
     */
    int getPetCount() const;

    /*
     * @brief Get the name of a specific pet.
     * @param petIndex Index of the pet.
     * @return The name of the pet.
     */
    string getPetName(int petIndex) const;

    /*
     * @brief Get the index of the person matched with a pet.
     * @param petIndex Index of the pet.
     * @return The index of the matched person.
     */
    int getMatchedPerson(int petIndex) const;

    /*
     * @brief Set the index of the person matched with a pet.
     * @param petIndex Index of the pet.
     * @param personIndex Index of the matched person.
     */
    void setMatchedPerson(int petIndex, int personIndex);

    /*
     * @brief Compare the preference rank of a pet for a person.
     * @param petIndex Index of the pet.
     * @param propPersonIndex Index of the proposed person.
     * @return True if the pet prefers the proposed person, false otherwise.
     */
    bool comparePetPreferenceRank(int petIndex, int proposedPersonIndex) const;

    /*
     * @brief Display data related to the Pet object.
     */
    void displayData() const;

private:
    string dataFile;                        // File containing data to initialize the Pet object.
    int petCount;                           // Total count of pets.
    vector<string> petNames;                // Names of pets.
    vector<vector<int>> petPreferences;     // Preferences of pets for matching with people.
    vector<vector<int>> petPreferenceRanks; // Preference ranks of pets for people.
    vector<int> matchedPeople;              // Indices of matched people.

    /*
     * @brief Load data from the specified file to initialize the Pet object.
     * @return True if data loading is successful, false otherwise.
     */
    bool loadData();
};
