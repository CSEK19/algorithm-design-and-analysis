/*
 * @file PointSet.cpp
 * @brief Implementation of the PointSet class methods.
 *
 * This file contains the implementation of the PointSet class methods, including constructors,
 * getter functions, methods for adding and printing points, and a destructor for cleanup.
 *
 * @author Phat Tran
 */

#include "PointSet.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

/*
 * @brief Default constructor for PointSet class.
 * @pre None.
 * @post An empty PointSet object is created.
 */
PointSet::PointSet() = default;

/*
 * @brief Destructor for PointSet class.
 * @pre None.
 * @post The PointSet object and its associated resources are deallocated.
 */
PointSet::~PointSet() {}

/*
 * @brief Constructor for PointSet class with initial points.
 * @param points Vector of points to initialize the PointSet.
 * @pre All points in the vector are valid Point objects.
 * @post A PointSet object is created with the specified initial points.
 */
PointSet::PointSet(const vector<Point> &points) : points(points) {}

/*
 * @brief Constructor for PointSet class with n points all set to (0.0, 0.0).
 * @param n The number of points to initialize in the PointSet.
 * @pre n is a non-negative integer.
 * @post A PointSet object is created with n points, all set to (0.0, 0.0).
 */
PointSet::PointSet(size_t n)
{
    // Initialize the PointSet with n points, all set to (0.0, 0.0).
    for (size_t i = 0; i < n; i++)
    {
        points.emplace_back(0.0, 0.0);
    }
}

/*
 * @brief Get the vector of points in the PointSet.
 * @return Vector of points in the PointSet.
 * @pre The PointSet object must exist.
 * @post The vector of points in the PointSet is returned.
 */
vector<Point> PointSet::getPoints() const
{
    return this->points;
}

/*
 * @brief Add a point to the PointSet.
 * @param point The point to be added.
 * @pre point is a valid Point object.
 * @post The specified point is added to the PointSet.
 */
void PointSet::addPoint(const Point &point)
{
    this->points.push_back(point);
}

/*
 * @brief Print the points in the PointSet.
 * @pre None.
 * @post None.
 */
void PointSet::printPoints() const
{
    cout << "Points:" << endl;
    for (const auto &point : points)
    {
        // Print the x and y coordinates and the index of each point
        cout << "(" << point.getX() << ", " << point.getY() << ", " << point.getIndex() << ") " << endl;
    }
}

/*
 * @brief Get the size of the PointSet.
 * @return The number of points in the PointSet.
 * @pre None.
 * @post The size of the PointSet is returned.
 */
size_t PointSet::size() const
{
    return this->points.size();
}

/*
 * @brief Access the point at the specified index using operator [].
 * @param index The index of the point to access.
 * @return Reference to the point at the specified index.
 * @pre index is a valid index within the PointSet.
 * @post The reference to the point at the specified index is returned.
 */
Point &PointSet::operator[](size_t index)
{
    if (index >= 0 && index < this->points.size())
    {
        return this->points[index];
    }
    else
    {
        cerr << "Error: Index out of bounds in PointSet." << endl;
        return this->points.front();
    }
}

/*
 * @brief Access the point at the specified index using operator [] (const version).
 * @param index The index of the point to access.
 * @return Const reference to the point at the specified index.
 * @pre index is a valid index within the PointSet.
 * @post The const reference to the point at the specified index is returned.
 */
const Point &PointSet::operator[](size_t index) const
{
    // Calling non-const version of operator[] using const_cast
    return const_cast<PointSet *>(this)->operator[](index);
}

/*
 * @brief Get an iterator pointing to the beginning of the PointSet.
 * @return Iterator pointing to the beginning of the PointSet.
 * @pre None.
 * @post Iterator pointing to the beginning of the PointSet is returned.
 */
std::vector<Point>::iterator PointSet::begin()
{
    return this->points.begin();
}

/*
 * @brief Get an iterator pointing to the end of the PointSet.
 * @return Iterator pointing to the end of the PointSet.
 * @pre None.
 * @post Iterator pointing to the end of the PointSet is returned.
 */
std::vector<Point>::iterator PointSet::end()
{
    return this->points.end();
}
