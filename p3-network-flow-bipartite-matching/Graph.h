/*
 * @file Graph.h
 * @brief Declaration of the Graph class, representing a graph.
 *
 * This file defines the Graph class, encapsulating the nodes and edges in a graph.
 * It includes a constructor, a destructor, and getter/setter functions for nodes and edges, various graph-related operations.
 *
 * @author Phat Tran
 */

#pragma once

#include <vector>
#include "Node.h"
#include "Edge.h"

/*
 * @brief Class representing a graph.
 */
class Graph
{
public:
    /*
     * @brief Constructor for Graph class.
     * @pre None.
     * @post A Graph object is created.
     */
    Graph();

    /*
     * @brief Destructor for Graph class.
     * @pre None.
     * @post The Graph object and its associated resources are deallocated.
     */
    ~Graph();

    // ---------------------------------------- Node-related functions ----------------------------------------
    /*
     * @brief Add a node to the graph.
     * @param node The node to add.
     * @pre The Graph object must exist.
     * @post The node is added to the graph.
     */
    void addNode(const Node &node);

    /*
     * @brief Get all the nodes in the graph.
     * @return A vector of all nodes in the graph.
     * @pre The Graph object must exist.
     * @post A vector of all nodes in the graph is returned.
     */
    const std::vector<Node> &getNodes() const;

    /*
     * @brief Get a node at a specific index in the graph.
     * @param index The index of the node.
     * @return The node at the specified index.
     * @pre The Graph object must exist.
     * @post The node at the specified index is returned.
     */
    const Node &getNode(int index) const;
    // --------------------------------------------------------------------------------------------------------

    // ---------------------------------------- Edge-related functions ----------------------------------------
    /*
     * @brief Add an edge to the graph.
     * @param source The index of the source node.
     * @param destination The index of the destination node.
     * @param hasFlow A boolean indicating if the edge has initial flow.
     * @pre The Graph object must exist.
     * @post An edge with the specified source, destination, and flow status is added to the graph.
     */
    void addEdge(int source, int destination, bool hasFlow);

    /*
     * @brief Get all the edges in the graph.
     * @return A vector of all edges in the graph.
     * @pre The Graph object must exist.
     * @post A vector of all edges in the graph is returned.
     */
    const std::vector<Edge> &getEdges() const;
    // --------------------------------------------------------------------------------------------------------

    // ----------------------------------- Residual graph-related functions -----------------------------------
    /*
     * @brief Create the residual graph based on the current graph's edges.
     * @pre The Graph object must exist.
     * @post The residual graph is created and updated based on the original graph's edges.
     */
    void createResidualGraph();

    /*
     * @brief Update the residual graph based on a given augmenting path.
     * @param augmentingPath A vector representing the augmenting path.
     * @pre The Graph object must exist.
     * @post The residual graph is updated using the given augmenting path.
     */
    void updateResidualGraph(const std::vector<int> &augmentingPath);
    // --------------------------------------------------------------------------------------------------------

    // ------------------------------------ Level graph-related functions -------------------------------------
    /*
     * @brief Create the level graph based on the current graph's structure.
     * @return A boolean indicating whether a level graph could be created.
     * @pre The Graph object must exist.
     * @post If successful, a level graph is created based on the original graph's structure.
     */
    bool createLevelGraph();

    /*
     * @brief Update the level graph based on a given augmenting path.
     * @param augmentingPath A vector representing the augmenting path.
     * @pre The Graph object must exist.
     * @post The level graph is updated using the given augmenting path.
     */
    void updateLevelGraph(const std::vector<int> &augmentingPath);

    /*
     * @brief Get the level graph.
     * @return A vector of vectors representing the level graph.
     * @pre The Graph object must exist.
     * @post A vector of vectors representing the level graph is returned.
     */
    const std::vector<std::vector<int>> &getLevelGraph() const;

    /*
     * @brief Get the level graph at a specific index.
     * @param index The index of the level graph to retrieve.
     * @return A vector representing the level graph at the specified index.
     * @pre The Graph object must exist.
     * @post A vector representing the level graph at the specified index is returned.
     */
    const std::vector<int> &getLevelGraphAt(int index) const;
    // --------------------------------------------------------------------------------------------------------

    // ---------------------------------------- Flow-related functions ----------------------------------------
    /*
     * @brief Augment the flow in the graph based on a given augmenting path.
     * @param augmentingPath A vector representing the augmenting path.
     * @pre The Graph object must exist.
     * @post The flow in the graph is augmented using the given augmenting path.
     */
    void augmentFlow(const std::vector<int> &augmentingPath);

    /*
     * @brief Remove a node and its incoming edges from the graph.
     * @param nodeIndex The index of the node to be removed.
     * @pre The Graph object must exist.
     * @post The specified node and its incoming edges are removed from the graph.
     */
    void removeNodeAndIncomingEdges(int nodeIndex);
    // --------------------------------------------------------------------------------------------------------

private:
    std::vector<Edge> edges;                     // Edges in the graph.
    std::vector<Node> nodes;                     // Nodes in the graph.
    std::vector<std::vector<int>> residualGraph; // Residual graph.
    std::vector<std::vector<int>> levelGraph;    // Level graph.
};
