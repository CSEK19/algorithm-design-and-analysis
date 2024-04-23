/*
 * @file Node.cpp
 * @brief Implementation of the Node class functions.
 *
 * This file contains the implementation of the functions declared in the Node class.
 * It defines the default constructor, parameterized constructor, destructor, and getter/setter functions.
 *
 * @author Phat Tran
 */

#include <iostream>
#include "Node.h"

using namespace std;

/*
 * @brief Default constructor for Node class.
 * @pre None.
 * @post A Node object is created with default values.
 */
Node::Node() : name(""), index(0), level(0) {}

/*
 * @brief Constructor for Node class.
 * @param name The name of the node.
 * @param index The index of the node.
 * @param level The level of the node.
 * @pre None.
 * @post A Node object is created with the specified name, index, and level.
 */
Node::Node(const string &name, int index, int level) : name(name), index(index), level(level) {}

/*
 * @brief Destructor for Node class.
 * @pre None.
 * @post The Node object and its associated resources are deallocated.
 */
Node::~Node() {}

/*
 * @brief Get the name of the node.
 * @return The name of the node.
 * @pre The Node object must exist.
 * @post The name of the node is returned.
 */
string Node::getName() const
{
	return this->name;
}

/*
 * @brief Get the index of the node.
 * @return The index of the node.
 * @pre The Node object must exist.
 * @post The index of the node is returned.
 */
int Node::getIndex() const
{
	return this->index;
}

/*
 * @brief Get the level of the node.
 * @return The level of the node.
 * @pre The Node object must exist.
 * @post The level of the node is returned.
 */
int Node::getLevel() const
{
	return this->level;
}

/*
 * @brief Set the name of the node.
 * @param name The new name to set.
 * @pre The Node object must exist.
 * @post The name of the node is updated to the new name.
 */
void Node::setName(const string &name)
{
	this->name = name;
}

/*
 * @brief Set the index of the node.
 * @param index The new index to set.
 * @pre The Node object must exist.
 * @post The index of the node is updated to the new index.
 */
void Node::setIndex(int index)
{
	this->index = index;
}

/*
 * @brief Set the level of the node.
 * @param level The new level to set.
 * @pre The Node object must exist.
 * @post The level of the node is updated to the new level.
 */
void Node::setLevel(int level)
{
	this->level = level;
}
