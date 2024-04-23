/*
 * @file P2.cpp
 * @brief Implementation of the main program for finding the closest pair of points.
 *
 * This file contains the main program implementation that reads a set of points from a file,
 * utilizes the ClosestPairAlgorithm to find the closest pair of points, and outputs the result.
 *
 * @author Phat Tran
 */

#include "Point.h"
#include "PointSet.h"
#include "ClosestPairAlgorithm.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

/*
 * @brief Main function for executing the closest pair algorithm.
 * @pre The input file "program2data.txt" must exist and be properly formatted.
 * @post The distances between the nearest pairs of points are calculated and displayed.
 * @usage This function is called to execute the closest pair algorithm.
 */
int main()
{
    // Open the input file
    const string inputFileName = "program2data.txt";
    ifstream inputFile(inputFileName);

    // Check if the file is successfully opened
    if (!inputFile.is_open())
    {
        cerr << "Error: Cannot open the input file." << endl;
        return 1;
    }

    // Read the number of points from the file
    int numPoints;
    inputFile >> numPoints;

    // Create a PointSet to store the input points
    PointSet pointSet;

    // Read and add each point from the file to the PointSet
    for (int i = 0; i < numPoints; i++)
    {
        double x, y;
        inputFile >> x >> y;
        pointSet.addPoint(Point(x, y));
    }

    // Close the input file
    inputFile.close();

    // Start measuring execution time
    auto start = high_resolution_clock::now();

    // Find the closest pair distance
    double closestPairDistance = ClosestPairAlgorithm::findClosestPairDistance(pointSet);

    // Stop measuring execution time
    auto stop = high_resolution_clock::now();

    // Calculate the execution time
    auto duration = duration_cast<milliseconds>(stop - start);

    // Print to console
    cout << "Closest pair distance: " << closestPairDistance << endl;
    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
