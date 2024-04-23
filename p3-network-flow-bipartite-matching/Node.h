/*
 * @file Node.h
 * @brief Declaration of the Node class, representing a node in a graph.
 *
 * This file defines the Node class, encapsulating the name, index, and level of a node in a graph.
 * It includes constructors for creating nodes, a destructor, getter functions to retrieve the name, index, and level,
 * setter functions to update the name, index, and level.
 *
 * @author Phat Tran
 */

#pragma once

#include <string>

/*
 * @brief Class representing a node in a graph.
 */
class Node
{
public:
	/*
	 * @brief Default constructor for Node class.
	 * @pre None.
	 * @post A Node object is created with default values.
	 */
	Node();

	/*
	 * @brief Constructor for Node class.
	 * @param name The name of the node.
	 * @param index The index of the node.
	 * @param level The level of the node.
	 * @pre None.
	 * @post A Node object is created with the specified name, index, and level.
	 */
	Node(const std::string &name, int index, int level);

	/*
	 * @brief Destructor for Node class.
	 * @pre None.
	 * @post The Node object and its associated resources are deallocated.
	 */
	~Node();

	/*
	 * @brief Get the name of the node.
	 * @return The name of the node.
	 * @pre The Node object must exist.
	 * @post The name of the node is returned.
	 */
	std::string getName() const;

	/*
	 * @brief Get the index of the node.
	 * @return The index of the node.
	 * @pre The Node object must exist.
	 * @post The index of the node is returned.
	 */
	int getIndex() const;

	/*
	 * @brief Get the level of the node.
	 * @return The level of the node.
	 * @pre The Node object must exist.
	 * @post The level of the node is returned.
	 */
	int getLevel() const;

	/*
	 * @brief Set the name of the node.
	 * @param name The new name to set.
	 * @pre The Node object must exist.
	 * @post The name of the node is updated to the new name.
	 */
	void setName(const std::string &name);

	/*
	 * @brief Set the index of the node.
	 * @param index The new index to set.
	 * @pre The Node object must exist.
	 * @post The index of the node is updated to the new index.
	 */
	void setIndex(int index);

	/*
	 * @brief Set the level of the node.
	 * @param level The new level to set.
	 * @pre The Node object must exist.
	 * @post The level of the node is updated to the new level.
	 */
	void setLevel(int level);

private:
	std::string name; // Name of a node.
	int index;		  // Index of a node.
	int level;		  // Level of a node.
};
