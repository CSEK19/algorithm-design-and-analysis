/*
 * @file StableMatching.cpp
 * @brief Implementation of the performStableMatching function using the Gale-Shapley algorithm.
 *
 * This file contains the implementation of the performStableMatching function,
 * which performs the stable matching algorithm between people and pets based on the Gale-Shapley algorithm.
 *
 * @author Phat Tran
 * @usage This function is used to perform the stable matching algorithm between people and pets.
 *
 */

#include "People.h"
#include "Pet.h"
#include <queue>

/*
 * @brief Perform stable matching between people and pets.
 * @pre Valid instances of People and Pet objects provided.
 * @post Returns true if the stable matching is successful, false otherwise.
 */
bool performStableMatching(People &people, Pet &pets)
{
    // Initialize an empty queue for all people to wait for matching
    queue<int> unmatchedPeople;
    for (int i = 0; i < people.getPeopleCount(); i++)
    {
        unmatchedPeople.push(i);
    }

    // Iterate through the queue until everyone is matched
    while (!unmatchedPeople.empty())
    {
        // Retrieve the index of the front person in unmatchedPeople
        int currentPerson = unmatchedPeople.front();
        unmatchedPeople.pop();

        // Get the preferred pet index from the person's preference list
        int preferredPetIndex = people.getPeoplePreference(currentPerson);

        // Adjust the index to match the vector range
        if (preferredPetIndex != -1)
        {
            preferredPetIndex -= 1;
        }
        else
        {
            // Invalid preference index
            return false;
        }

        // Retrieve the current master of the preferred pet
        int currentPetMaster = pets.getMatchedPerson(preferredPetIndex);

        if (currentPetMaster == -1)
        {
            // The pet preferred by the person is unmatched
            // Match the person and the pet with each other
            pets.setMatchedPerson(preferredPetIndex, currentPerson);
            people.setMatchedPet(currentPerson, preferredPetIndex);
        }
        else if (pets.comparePetPreferenceRank(preferredPetIndex, currentPerson))
        {
            // The pet prefers the person to its current master
            // Let the current master wait in unmatchedPeople, and remove their matching
            unmatchedPeople.push(currentPetMaster);
            people.setMatchedPet(currentPetMaster, -1);

            // Match the pet with a new master it prefers
            pets.setMatchedPerson(preferredPetIndex, currentPerson);
            people.setMatchedPet(currentPerson, preferredPetIndex);
        }
        else
        {
            // The pet prefers its current master to the person
            // Let the person wait in unmatchedPeople
            unmatchedPeople.push(currentPerson);
        }
    }

    return true;
}
