/*
 * @file P1.cpp
 * @brief Main function for executing the stable matching algorithm.
 *
 * This file contains the main function that initializes People and Pet objects,
 * performs the Gale-Shapley algorithm for stable matching, and displays the results.
 *
 * @author Phat Tran
 * @usage This program is used to demonstrate the stable matching algorithm between people and pets.
 *
 */

#include "People.h"
#include "Pet.h"
#include "StableMatching.h"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

/*
 * @brief Main function for executing the stable matching algorithm.
 * @pre None.
 * @post The stable matching algorithm is performed, and the results are displayed.
 * @usage This function is called to execute the stable matching algorithm between people and pets.
 */
int main()
{
	// Input file
	string dataFile = "program1data.txt";

	// Initialize People and Pet objects
	People people(dataFile);
	Pet pets(dataFile);

	/* Display data for testing purposes
	people.displayData();
	cout << endl;
	pets.displayData();
	*/

	cout << "\nPerforming the Gale-Shapley algorithm..." << endl;
	bool hasStableMatching = false;

	// Get the start time point
	auto start = chrono::high_resolution_clock::now();

	hasStableMatching = performStableMatching(people, pets);

	// Get the end time point
	auto end = chrono::high_resolution_clock::now();

	if (hasStableMatching)
	{
		cout << "Successfully obtained a stable matching!" << endl;
	}
	else
	{
		cerr << "Failed to obtain a stable matching" << endl;
		exit(EXIT_FAILURE);
	}

	// Displaying the results of the stable matching algorithm for people and pets
	cout << "\nResults of the stable matching algorithm:" << endl;
	for (int i = 0; i < people.getPeopleCount(); i++)
	{
		cout << people.getPeopleName(i) << " / "
			 << pets.getPetName(people.getMatchedPet(i))
			 << endl;
	}

	// Calculate the duration in microseconds
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

	// Display the duration in microseconds
	cout << "\nThe elapsed time is: " << duration.count() << " microseconds" << endl;

	return EXIT_SUCCESS;
}
