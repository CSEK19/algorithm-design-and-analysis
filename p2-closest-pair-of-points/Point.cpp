/*
 * @file Point.cpp
 * @brief Implementation of the Point class methods.
 *
 * This file contains the implementation of the Point class methods, including constructors, getter and setter functions,
 * static member functions for coordinate-based comparisons, a distance calculation method between two points, and a destructor.
 *
 * @author Phat Tran
 */

#include "Point.h"

/*
 * @brief Constructor for Point class.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @param index The index of the point, optional with a default of -1.
 * @pre None.
 * @post A Point object is created with the specified x-coordinate, y-coordinate, and associated index if provided.
 */
Point::Point(double x, double y, int index) : x(x), y(y), index(index) {}

/*
 * @brief Destructor for Point class.
 * @pre None.
 * @post The Point object and its associated resources are deallocated.
 */
Point::~Point() {}

/*
 * @brief Get the x-coordinate of the point.
 * @return The x-coordinate.
 * @pre The Point object must exist.
 * @post The x-coordinate of the point is returned.
 */
double Point::getX() const
{
    return this->x;
}

/*
 * @brief Get the y-coordinate of the point.
 * @return The y-coordinate.
 * @pre The Point object must exist.
 * @post The y-coordinate of the point is returned.
 */
double Point::getY() const
{
    return this->y;
}

/*
 * @brief Get the index of the point.
 * @return The index of the point.
 * @pre The Point object must exist.
 * @post The index of the point is returned.
 */
int Point::getIndex() const
{
    return this->index;
}

/*
 * @brief Set the index of the point.
 * @param newIndex The new index to set.
 * @pre The Point object must exist.
 * @post The index of the point is updated to the new index.
 */
void Point::setIndex(int newIndex)
{
    this->index = newIndex;
}

/*
 * @brief Compare two points based on their x-coordinates.
 * @param a The first point.
 * @param b The second point.
 * @return True if the x-coordinate of point a is less than the x-coordinate of point b, false otherwise.
 * @pre The points a and b must be valid Point objects.
 * @post The order of the points is unchanged; no side effects on the input points.
 */
bool Point::compareX(const Point &a, const Point &b)
{
    return a.getX() < b.getX();
}

/*
 * @brief Compare two points based on their y-coordinates.
 * @param a The first point.
 * @param b The second point.
 * @return True if the y-coordinate of point a is less than the y-coordinate of point b, false otherwise.
 * @pre The points a and b must be valid Point objects.
 * @post The order of the points is unchanged; no side effects on the input points.
 */
bool Point::compareY(const Point &a, const Point &b)
{
    return a.getY() < b.getY();
}

/*
 * @brief Calculate the Euclidean distance between two points.
 * @param a The first point.
 * @param b The second point.
 * @return The Euclidean distance between the two points.
 * @pre The points a and b must be valid Point objects.
 * @post None.
 */
double Point::calculateDistance(const Point &a, const Point &b)
{
    // Compute the difference in x and y values
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();

    // Return the square root of the sum of squares
    return sqrt(dx * dx + dy * dy);
}
