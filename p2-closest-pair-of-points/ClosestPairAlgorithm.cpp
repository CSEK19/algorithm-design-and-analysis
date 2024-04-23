/*
 * @file ClosestPairAlgorithm.cpp
 * @brief Implementation of the ClosestPairAlgorithm class for finding the closest pair of points.
 *
 * This file contains the implementation of the ClosestPairAlgorithm class, which provides functions
 * to find the closest pair of points in a given PointSet. It includes a static function for finding
 * the closest pair distance, private recursive functions for the algorithm, as well as helper
 * functions for brute-force calculation, printing information about the closest pair, and a utility
 * function to find the smaller of two double values.
 *
 * @author Phat Tran
 */

#include "ClosestPairAlgorithm.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

/*
 * @brief Find the closest pair distance using the divide and conquer algorithm.
 * @param pointSet The set of points to search for the closest pair.
 * @return The distance between the closest pair of points.
 * @pre The PointSet object must exist and contain at least two points.
 * @post The distance between the closest pair of points is returned.
 */
double ClosestPairAlgorithm::findClosestPairDistance(const PointSet &pointSet)
{
    // Check if the point set has enough points to find a pair
    int size = static_cast<int>(pointSet.size());
    if (size < 2)
    {
        // Print an error message and return the maximum possible distance
        cerr << "Error: The closest pair algorithm requires at least two points for accurate computation." << endl;
        return numeric_limits<double>::max();
    }

    // Sort points by x-coordinate
    PointSet sortedPointsX = pointSet;
    sort(sortedPointsX.begin(), sortedPointsX.end(), Point::compareX);

    // Sort points by y-coordinate
    PointSet sortedPointsY = pointSet;
    sort(sortedPointsY.begin(), sortedPointsY.end(), Point::compareY);

    // Set indices for each point in the sorted order
    for (int i = 0; i < size; i++)
    {
        sortedPointsX[i].setIndex(i);
        sortedPointsY[i].setIndex(i);
    }

    // Call the recursive function with the entire range of points
    return findClosestPairRecursive(sortedPointsX, sortedPointsY, 0, size - 1);
}

/*
 * @brief Recursive function to find the closest pair distance using the divide and conquer algorithm.
 * @param sortedPointsX The PointSet containing the points sorted by x-coordinate.
 * @param sortedPointsY The PointSet containing the points sorted by y-coordinate.
 * @param leftIndex Index of the leftmost point.
 * @param rightIndex Index of the rightmost point.
 * @return The distance between the closest pair of points in the specified range.
 * @pre The PointSet objects must not be empty.
 * @post The distance between the closest pair of points in the specified range is returned.
 */
double ClosestPairAlgorithm::findClosestPairRecursive(const PointSet &sortedPointsX, const PointSet &sortedPointsY, int leftIndex, int rightIndex)
{
    // Base case: Use brute force for subarrays with three or fewer points
    if (rightIndex - leftIndex <= 2)
    {
        double minDistance = bruteForceClosestPairDistance(sortedPointsX, leftIndex, rightIndex);

        // Print the minimum distance with corresponding indices and return it
        printMinDistance(minDistance, leftIndex, rightIndex);
        return minDistance;
    }

    // Split the subarray into two halves
    int mid = (leftIndex + rightIndex) / 2;
    Point midPoint = sortedPointsX[mid];

    // Create sets for points on the left and right of the dividing line, sorted by y-coordinate
    PointSet leftSortedPointsY;
    PointSet rightSortedPointsY;
    int leftIndexY = 0;
    int rightIndexY = 0;

    // Populate points based on the y-coordinate
    for (int i = 0; i <= (rightIndex - leftIndex) && i < sortedPointsY.size(); i++)
    {
        if (((sortedPointsY[i].getX() < midPoint.getX()) ||
             (sortedPointsY[i].getX() == midPoint.getX() && sortedPointsY[i].getY() <= midPoint.getY())) &&
            (leftIndexY < mid))
        {
            // Point is on the left side
            leftSortedPointsY.addPoint(sortedPointsY[i]);
            leftSortedPointsY[leftIndexY].setIndex(leftIndexY);
            leftIndexY++;
        }
        else
        {
            // Point is on the right side
            rightSortedPointsY.addPoint(sortedPointsY[i]);
            rightSortedPointsY[rightIndexY].setIndex(rightIndexY);
            rightIndexY++;
        }
    }

    // Recursively find the closest pair distance in the left and right halves
    double leftDistance = findClosestPairRecursive(sortedPointsX, leftSortedPointsY, leftIndex, mid);
    double rightDistance = findClosestPairRecursive(sortedPointsX, rightSortedPointsY, mid + 1, rightIndex);

    // Find the minimum distance among the two halves
    double minDistance = getMinimumValue(leftDistance, rightDistance);

    // Merge the two halves and find the minimum distance in the strip
    PointSet strip;
    for (int i = 0; (i < rightIndex - leftIndex + 1) && (i < sortedPointsY.size()); i++)
    {
        // Add the point is within the strip of width 2 * minDistance around the mid point
        if (abs(sortedPointsY[i].getX() - midPoint.getX()) < minDistance)
        {
            strip.addPoint(sortedPointsY[i]);
        }
    }

    // Check for closer pairs in the strip
    for (int i = 0; i < strip.size(); i++)
    {
        // Loop through points within minDistance in y-coordinate from the current point
        for (int j = i + 1; (j < strip.size()) && (strip[j].getY() - strip[i].getY() < minDistance); j++)
        {
            double distance = Point::calculateDistance(strip[i], strip[j]);
            minDistance = getMinimumValue(distance, minDistance);
        }
    }

    // Print the minimum distance with corresponding indices and return it
    printMinDistance(minDistance, leftIndex, rightIndex);
    return minDistance;
}

/*
 * @brief Calculate the closest pair distance using a brute-force method.
 * @param points The PointSet containing the points.
 * @param leftIndex Index of the leftmost point.
 * @param rightIndex Index of the rightmost point.
 * @return The distance between the closest pair of points in the specified range.
 * @pre The PointSet object must not be empty.
 * @post The distance between the closest pair of points in the specified range is returned.
 */
double ClosestPairAlgorithm::bruteForceClosestPairDistance(const PointSet &points, int leftIndex, int rightIndex)
{
    // Initialize the minimum distance to the maximum possible value
    double minDistance = numeric_limits<double>::max();

    for (int i = leftIndex; i <= rightIndex; i++)
    {
        for (int j = i + 1; j <= rightIndex; j++)
        {
            double distance = Point::calculateDistance(points[i], points[j]);
            minDistance = getMinimumValue(distance, minDistance);
        }
    }

    return minDistance;
}

/*
 * @brief Helper function to print information about the closest pair of points.
 * @param minDistance The distance between the closest pair of points.
 * @param leftPointIndex Index of the leftmost point in the pair.
 * @param rightPointIndex Index of the rightmost point in the pair.
 * @pre minDistance is the minimum distance between the points at leftPointIndex and rightPointIndex.
 * @post Detailed information about the closest pair of points is printed.
 */
void ClosestPairAlgorithm::printMinDistance(double minDistance, int leftPointIndex, int rightPointIndex)
{
    cout << "D[" << leftPointIndex << "," << rightPointIndex << "]: " << fixed << setprecision(4) << minDistance << endl;
}

/*
 * @brief Returns the minimum of two double values.
 * @param firstValue The first double value.
 * @param secondValue The second double value.
 * @return The smaller of the two input values.
 * @pre The input values firstValue and secondValue are valid double numbers.
 * @post The minimum value between firstValue and secondValue is returned.
 */
double ClosestPairAlgorithm::getMinimumValue(double firstValue, double secondValue)
{
    return (firstValue < secondValue) ? firstValue : secondValue;
}