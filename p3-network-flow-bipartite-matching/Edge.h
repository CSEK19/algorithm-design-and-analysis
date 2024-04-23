/*
 * @file Edge.h
 * @brief Declaration of the Edge class, representing an edge in a graph.
 *
 * This file defines the Edge class, encapsulating the source and destination nodes in a graph and whether there is a flow on the edge.
 * It includes a constructors, a destructor, and getter/setter functions for the source, destination, and flow status.
 *
 * @author Phat Tran
 */

#pragma once

#include "Node.h"

/*
 * @brief Class representing an edge in a graph.
 */
class Edge
{
public:
    /*
     * @brief Constructor for Edge class.
     * @param source The index of the source node.
     * @param destination The index of the destination node.
     * @param hasFlow Represents whether there is a flow on the edge.
     * @pre None.
     * @post An Edge object is created with the specified source, destination, and flow status.
     */
    Edge(int source, int destination, bool hasFlow);

    /*
     * @brief Destructor for Edge class.
     * @pre None.
     * @post The Edge object and its associated resources are deallocated.
     */
    ~Edge();

    /*
     * @brief Get the index of the source node.
     * @return The index of the source node.
     * @pre The Edge object must exist.
     * @post The index of the source node is returned.
     */
    int getSourceIndex() const;

    /*
     * @brief Get the index of the destination node.
     * @return The index of the destination node.
     * @pre The Edge object must exist.
     * @post The index of the destination node is returned.
     */
    int getDestinationIndex() const;

    /*
     * @brief Check whether there is a flow on the edge.
     * @return True if there is a flow on the edge, false otherwise.
     * @pre The Edge object must exist.
     * @post The flow status of the edge is returned.
     */
    bool hasFlow() const;

    /*
     * @brief Set the flow status of the edge.
     * @param hasFlow The new flow status to set.
     * @pre The Edge object must exist.
     * @post The flow status of the edge is updated to the new status.
     */
    void setFlow(bool hasFlow);

private:
    int source;      // Index of the source node.
    int destination; // Index of the destination node.
    bool flow;       // Represents whether there is a flow on the edge.
};
