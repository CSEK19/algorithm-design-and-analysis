/*
 * @file Edge.cpp
 * @brief Implementation of the Edge class.
 *
 * This file contains the implementation of the functions declared in the Edge class.
 * It includes a constructor, a destructor, and getter/setter functions for the source, destination, and flow status of an edge.
 *
 * @author Phat Tran
 */

#include "Edge.h"

/*
 * @brief Constructor for Edge class.
 * @param source The index of the source node.
 * @param destination The index of the destination node.
 * @param hasFlow Represents whether there is a flow on the edge.
 * @pre None.
 * @post An Edge object is created with the specified source, destination, and flow status.
 */
Edge::Edge(int source, int destination, bool hasFlow) : source(source), destination(destination), flow(hasFlow) {}

/*
 * @brief Destructor for Edge class.
 * @pre None.
 * @post The Edge object and its associated resources are deallocated.
 */
Edge::~Edge() {}

/*
 * @brief Get the index of the source node.
 * @return The index of the source node.
 * @pre The Edge object must exist.
 * @post The index of the source node is returned.
 */
int Edge::getSourceIndex() const
{
    return this->source;
}

/*
 * @brief Get the index of the destination node.
 * @return The index of the destination node.
 * @pre The Edge object must exist.
 * @post The index of the destination node is returned.
 */
int Edge::getDestinationIndex() const
{
    return this->destination;
}

/*
 * @brief Check whether there is a flow on the edge.
 * @return True if there is a flow on the edge, false otherwise.
 * @pre The Edge object must exist.
 * @post The flow status of the edge is returned.
 */
bool Edge::hasFlow() const
{
    return this->flow;
}

/*
 * @brief Set the flow status of the edge.
 * @param hasFlow The new flow status to set.
 * @pre The Edge object must exist.
 * @post The flow status of the edge is updated to the new status.
 */
void Edge::setFlow(bool hasFlow)
{
    this->flow = hasFlow;
}
