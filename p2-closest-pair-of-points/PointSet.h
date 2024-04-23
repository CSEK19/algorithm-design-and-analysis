/*
 * @file PointSet.h
 * @brief Declaration of the PointSet class representing a set of points in 2D space.
 *
 * This file defines the PointSet class, which manages a set of points in a 2D space. It encompasses
 * constructors, getter functions, methods for adding and printing points, and a destructor for cleanup.
 *
 * @author Phat Tran
 */

#pragma once

#include "Point.h"
#include <vector>

/*
 * @brief Class representing a set of points in a 2D space.
 */
class PointSet
{
private:
    std::vector<Point> points; // Container to store the points in the 2D space.

public:
    /*
     * @brief Default constructor for PointSet class.
     * @pre None.
     * @post An empty PointSet object is created.
     */
    PointSet();

    /*
     * @brief Destructor for PointSet class.
     * @pre None.
     * @post The PointSet object and its associated resources are deallocated.
     */
    ~PointSet();

    /*
     * @brief Constructor for PointSet class with initial points.
     * @param points Vector of points to initialize the PointSet.
     * @pre All points in the vector are valid Point objects.
     * @post A PointSet object is created with the specified initial points.
     */
    explicit PointSet(const std::vector<Point> &points);

    /*
     * @brief Constructor for PointSet class with n points all set to (0.0, 0.0).
     * @param n The number of points to initialize in the PointSet.
     * @pre n is a non-negative integer.
     * @post A PointSet object is created with n points, all set to (0.0, 0.0).
     */
    PointSet(size_t n);

    /*
     * @brief Get the vector of points in the PointSet.
     * @return Vector of points in the PointSet.
     * @pre The PointSet object must exist.
     * @post The vector of points in the PointSet is returned.
     */
    std::vector<Point> getPoints() const;

    /*
     * @brief Add a point to the PointSet.
     * @param point The point to be added.
     * @pre point is a valid Point object.
     * @post The specified point is added to the PointSet.
     */
    void addPoint(const Point &point);

    /*
     * @brief Print the points in the PointSet.
     * @pre None.
     * @post None.
     */
    void printPoints() const;

    /*
     * @brief Get the size of the PointSet.
     * @return The number of points in the PointSet.
     * @pre None.
     * @post The size of the PointSet is returned.
     */
    size_t size() const;

    /*
     * @brief Access the point at the specified index using operator [].
     * @param index The index of the point to access.
     * @return Reference to the point at the specified index.
     * @pre index is a valid index within the PointSet.
     * @post The reference to the point at the specified index is returned.
     */
    Point &operator[](size_t index);

    /*
     * @brief Access the point at the specified index using operator [] (const version).
     * @param index The index of the point to access.
     * @return Const reference to the point at the specified index.
     * @pre index is a valid index within the PointSet.
     * @post The const reference to the point at the specified index is returned.
     */
    const Point &operator[](size_t index) const;

    /*
     * @brief Get an iterator pointing to the beginning of the PointSet.
     * @return Iterator pointing to the beginning of the PointSet.
     * @pre None.
     * @post Iterator pointing to the beginning of the PointSet is returned.
     */
    std::vector<Point>::iterator begin();

    /*
     * @brief Get an iterator pointing to the end of the PointSet.
     * @return Iterator pointing to the end of the PointSet.
     * @pre None.
     * @post Iterator pointing to the end of the PointSet is returned.
     */
    std::vector<Point>::iterator end();
};
