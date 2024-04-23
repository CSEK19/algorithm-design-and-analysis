/*
 * @file ClosestPairAlgorithm.h
 * @brief Declaration of the ClosestPairAlgorithm class for finding the closest pair of points.
 *
 * This file contains the declaration of the ClosestPairAlgorithm class, which provides functions
 * to find the closest pair of points in a given PointSet. It includes a static function for finding
 * the closest pair distance, private recursive functions for the algorithm, as well as helper
 * functions for brute-force calculation, printing information about the closest pair, and a utility
 * function to find the smaller of two double values.
 *
 * @author Phat Tran
 */

#pragma once

#include "PointSet.h"

/*
 * @brief Class representing an algorithm to find the closest pair of points.
 */
class ClosestPairAlgorithm
{
public:
    /*
     * @brief Find the closest pair distance using the divide and conquer algorithm.
     * @param pointSet The set of points to search for the closest pair.
     * @return The distance between the closest pair of points.
     * @pre The PointSet object must exist and contain at least two points.
     * @post The distance between the closest pair of points is returned.
     */
    static double findClosestPairDistance(const PointSet &pointSet);

private:
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
    static double findClosestPairRecursive(const PointSet &sortedPointsX, const PointSet &sortedPointsY, int leftIndex, int rightIndex);

    /*
     * @brief Calculate the closest pair distance using a brute-force method.
     * @param points The PointSet containing the points.
     * @param leftIndex Index of the leftmost point.
     * @param rightIndex Index of the rightmost point.
     * @return The distance between the closest pair of points in the specified range.
     * @pre The PointSet object must not be empty.
     * @post The distance between the closest pair of points in the specified range is returned.
     */
    static double bruteForceClosestPairDistance(const PointSet &points, int leftIndex, int rightIndex);

    /*
     * @brief Helper function to print information about the closest pair of points.
     * @param minDistance The distance between the closest pair of points.
     * @param leftPointIndex Index of the leftmost point in the pair.
     * @param rightPointIndex Index of the rightmost point in the pair.
     * @pre minDistance is the minimum distance between the points at leftPointIndex and rightPointIndex.
     * @post Detailed information about the closest pair of points is printed.
     */
    static void printMinDistance(double minDistance, int leftPointIndex, int rightPointIndex);

    /*
     * @brief Returns the minimum of two double values.
     * @param firstValue The first double value.
     * @param secondValue The second double value.
     * @return The smaller of the two input values.
     * @pre The input values firstValue and secondValue are valid double numbers.
     * @post The minimum value between firstValue and secondValue is returned.
     */
    static double getMinimumValue(double firstValue, double secondValue);
};
