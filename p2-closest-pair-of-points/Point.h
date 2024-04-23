/*
 * @file Point.h
 * @brief Declaration of the Point class, representing a point in 2D space.
 *
 * This file defines the Point class, encapsulating a point's coordinates in a 2D space. It includes
 * constructors, getter and setter functions, static member functions for coordinate-based comparisons,
 * a distance calculation method between two points, and a destructor.
 *
 * @author Phat Tran
 */

#pragma once

#include <cmath>

/*
 * @brief Class representing a point in a 2D space.
 */
class Point
{
private:
    int index; // Index of the point.
    double x;  // x-coordinate of the point in a 2D space.
    double y;  // y-coordinate of the point in a 2D space.

public:
    /*
     * @brief Constructor for Point class.
     * @param x The x-coordinate of the point.
     * @param y The y-coordinate of the point.
     * @param index The index of the point, optional with a default of -1.
     * @pre None.
     * @post A Point object is created with the specified x-coordinate, y-coordinate, and associated index if provided.
     */
    Point(double x, double y, int index = -1);

    /*
     * @brief Destructor for Point class.
     * @pre None.
     * @post The Point object and its associated resources are deallocated.
     */
    ~Point();

    /*
     * @brief Get the x-coordinate of the point.
     * @return The x-coordinate.
     * @pre The Point object must exist.
     * @post The x-coordinate of the point is returned.
     */
    double getX() const;

    /*
     * @brief Get the y-coordinate of the point.
     * @return The y-coordinate.
     * @pre The Point object must exist.
     * @post The y-coordinate of the point is returned.
     */
    double getY() const;

    /*
     * @brief Get the index of the point.
     * @return The index of the point.
     * @pre The Point object must exist.
     * @post The index of the point is returned.
     */
    int getIndex() const;

    /*
     * @brief Set the index of the point.
     * @param newIndex The new index to set.
     * @pre The Point object must exist.
     * @post The index of the point is updated to the new index.
     */
    void setIndex(int newIndex);

    /*
     * @brief Compare two points based on their x-coordinates.
     * @param a The first point.
     * @param b The second point.
     * @return True if the x-coordinate of point a is less than the x-coordinate of point b, false otherwise.
     * @pre The points a and b must be valid Point objects.
     * @post The order of the points is unchanged; no side effects on the input points.
     */
    static bool compareX(const Point &a, const Point &b);

    /*
     * @brief Compare two points based on their y-coordinates.
     * @param a The first point.
     * @param b The second point.
     * @return True if the y-coordinate of point a is less than the y-coordinate of point b, false otherwise.
     * @pre The points a and b must be valid Point objects.
     * @post The order of the points is unchanged; no side effects on the input points.
     */
    static bool compareY(const Point &a, const Point &b);

    /*
     * @brief Calculate the Euclidean distance between two points.
     * @param a The first point.
     * @param b The second point.
     * @return The Euclidean distance between the two points.
     * @pre The points a and b must be valid Point objects.
     * @post None.
     */
    static double calculateDistance(const Point &a, const Point &b);
};
