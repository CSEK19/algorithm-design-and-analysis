/*
 * @file Graph.cpp
 * @brief Implementation of the Graph class functions.
 *
 * This file contains the implementation of the functions declared in the Graph class.
 * It includes a constructor, a destructor, and getter/setter functions for nodes and edges, various graph-related operations.
 *
 * @author Phat Tran
 */

#include <queue>
#include <iostream>
#include "Graph.h"

using namespace std;

// Constant representing the special index for the sink node in the graph
const int SINK_NODE_INDEX = -1;

/*
 * @brief Constructor for Graph class.
 * @pre None.
 * @post A Graph object is created.
 */
Graph::Graph() {}

/*
 * @brief Destructor for Graph class.
 * @pre None.
 * @post The Graph object and its associated resources are deallocated.
 */
Graph::~Graph() {}

// ---------------------------------------- Node-related functions ----------------------------------------
/*
 * @brief Add a node to the graph.
 * @param node The node to add.
 * @pre The Graph object must exist.
 * @post The node is added to the graph.
 */
void Graph::addNode(const Node &node) { this->nodes.push_back(node); }

/*
 * @brief Get all the nodes in the graph.
 * @return A vector of all nodes in the graph.
 * @pre The Graph object must exist.
 * @post A vector of all nodes in the graph is returned.
 */
const vector<Node> &Graph::getNodes() const { return this->nodes; }

/*
 * @brief Get a node at a specific index in the graph.
 * @param index The index of the node.
 * @return The node at the specified index.
 * @pre The Graph object must exist.
 * @post The node at the specified index is returned.
 */
const Node &Graph::getNode(int index) const
{
    // Check if index is out of range
    if (index < 0 || index >= this->nodes.size())
    {
        cerr << "Error: Index out of range, returning the first node." << endl;
        return this->nodes.front();
    }

    // Return the node at the specified index
    return this->nodes[index];
}
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
void Graph::addEdge(int source, int destination, bool hasFlow)
{
    // Create and add a new Edge to the edges vector
    Edge edge(source, destination, hasFlow);
    this->edges.push_back(edge);
}

/*
 * @brief Get all the edges in the graph.
 * @return A vector of all edges in the graph.
 * @pre The Graph object must exist.
 * @post A vector of all edges in the graph is returned.
 */
const vector<Edge> &Graph::getEdges() const { return this->edges; }
// --------------------------------------------------------------------------------------------------------

// ----------------------------------- Residual graph-related functions -----------------------------------
/*
 * @brief Create the residual graph based on the current graph's edges.
 * @pre The Graph object must exist.
 * @post The residual graph is created and updated based on the original graph's edges.
 */
void Graph::createResidualGraph()
{
    // Calculate total number of nodes and divide into left and right partitions
    int totalNodes = static_cast<int>(this->nodes.size());
    int leftPartition = totalNodes / 2;

    // Initialize the residual graph with empty adjacency lists
    int totalResidualGraphNodes = totalNodes + 2;
    this->residualGraph.resize(totalResidualGraphNodes);

    // Connect source node (0) to nodes in the left partition (1 to leftPartition)
    for (int i = 1; i <= leftPartition; i++)
    {
        this->residualGraph[0].push_back(i);
    }

    // Create residual graph from existing edges
    for (int i = 0; i < this->edges.size(); i++)
    {
        Edge edge = this->edges[i];
        int sourceIndex = edge.getSourceIndex();
        int destIndex = edge.getDestinationIndex();
        this->residualGraph[sourceIndex].push_back(destIndex);
    }

    // Connect nodes in the right partition (leftPartition + 1 to totalNodes) to the sink node (totalNodes + 1)
    for (int i = leftPartition + 1; i <= totalNodes; i++)
    {
        this->residualGraph[i].push_back(totalNodes + 1);
    }

    // Connect the sink node to a special node (-1) to represent infinity
    int sinkNodeIndex = totalNodes + 1;
    this->residualGraph[sinkNodeIndex].push_back(-1);

    // Add source node (with empty name, index 0, and level 0)
    Node sourceNode("", 0, 0);
    this->nodes.insert(nodes.begin(), sourceNode);

    // Add sink node (with empty name, index sinkNodeIndex, and level 0)
    Node sinkNode("", sinkNodeIndex, 0);
    this->nodes.push_back(sinkNode);
}

/*
 * @brief Update the residual graph based on a given augmenting path.
 * @param augmentingPath A vector representing the augmenting path.
 * @pre The Graph object must exist.
 * @post The residual graph is updated using the given augmenting path.
 */
void Graph::updateResidualGraph(const vector<int> &augmentingPath)
{
    // Iterate through the nodes in the given path
    for (int i = 0; i < augmentingPath.size() - 1; i++)
    {
        // Current node in the path
        int currentNode = augmentingPath[i];

        // Next node in the path
        int nextNodeIndex = i + 1;
        int nextNode = augmentingPath[nextNodeIndex];

        // Find the edge in the residual graph
        vector<int>::iterator it = find(this->residualGraph[currentNode].begin(), this->residualGraph[currentNode].end(), nextNode);

        // Check if the edge is found in the residual graph
        if (it != residualGraph[currentNode].end())
        {
            // Reverse the edge if it exists in the residual graph
            // Remove the forward edge (currentNode -> nextNode) and add the reverse edge (nextNode -> currentNode)
            this->residualGraph[currentNode].erase(it);
            this->residualGraph[nextNode].push_back(currentNode);
        }
    }
}
// --------------------------------------------------------------------------------------------------------

// ------------------------------------ Level graph-related functions -------------------------------------
/*
 * @brief Create the residual graph based on the current graph's edges.
 * @pre The Graph object must exist.
 * @post The residual graph is created and updated based on the original graph's edges.
 */
bool Graph::createLevelGraph()
{
    // Check if the graph is empty
    if (nodes.empty())
    {
        cout << "Message: The residual graph is empty." << endl;
        return false;
    }

    // Flag indicating whether a path to the sink node exists
    bool hasPathToSink = false;

    // Create a copy of the residual graph for level tracking
    this->levelGraph = this->residualGraph;

    // Mark nodes as visited during BFS
    vector<bool> visited(nodes.size(), false);

    // Start BFS from the source node
    queue<Node> nodeQueue;
    nodeQueue.push(nodes[0]);

    while (!nodeQueue.empty())
    {
        const Node &currentNode = nodeQueue.front();
        const int currentLevel = currentNode.getLevel();
        const int currentIndex = currentNode.getIndex();
        nodeQueue.pop();

        // Get the adjacent nodes in the current level
        const vector<int> &currentLevelGraph = levelGraph[currentIndex];
        int numAdjacentNodes = static_cast<int>(currentLevelGraph.size());

        for (int i = 0; i < numAdjacentNodes; i++)
        {
            const int adjancentIndex = currentLevelGraph[i]; // Index of the adjacent node

            // Check if the sink node is reached
            if (adjancentIndex == SINK_NODE_INDEX)
            {
                hasPathToSink = true;
                break;
            }
            // Explore unvisited nodes
            else if (!visited[adjancentIndex])
            {
                visited[adjancentIndex] = true;                   // Mark the adjacent node as visited
                nodes[adjancentIndex].setLevel(currentLevel + 1); // Set the level of the adjacent node to the current level + 1
                nodeQueue.push(nodes[adjancentIndex]);            // Add the adjacent node to the queue
            }
            // Remove backward edges to nodes at lower levels
            else if (nodes[adjancentIndex].getLevel() < currentLevel + 1)
            {
                levelGraph[currentIndex].erase(currentLevelGraph.begin() + i);
            }
        }

        // Mark the current node as visited
        visited[currentIndex] = true;
    }

    return hasPathToSink;
}

/*
 * @brief Update the level graph based on a given augmenting path.
 * @param augmentingPath A vector representing the augmenting path.
 * @pre The Graph object must exist.
 * @post The level graph is updated using the given augmenting path.
 */
void Graph::updateLevelGraph(const vector<int> &augmentingPath)
{
    for (int i = 0; i < augmentingPath.size() - 1; i++)
    {
        // Current node in the path
        int currentNode = augmentingPath[i];

        // Next node in the path
        int nextNodeIndex = i + 1;
        int nextNode = augmentingPath[nextNodeIndex];

        // Find the edge in the level graph and delete it
        vector<int>::iterator it = find(this->levelGraph[currentNode].begin(), this->levelGraph[currentNode].end(), nextNode);

        // Check if the edge is found in the level graph
        if (it != levelGraph[currentNode].end())
        {
            // Delete the edge from the level graph
            this->levelGraph[currentNode].erase(it);
        }
    }
}

/*
 * @brief Get the level graph.
 * @return A vector of vectors representing the level graph.
 * @pre The Graph object must exist.
 * @post A vector of vectors representing the level graph is returned.
 */
const vector<int> &Graph::getLevelGraphAt(int index) const
{
    // Check if the index is within the valid range
    if (index < 0 || index >= this->levelGraph.size())
    {
        cerr << "Error: Index out of range, returning the level graph of the first node." << endl;
        return this->levelGraph.front();
    }

    // Return the level graph for the specified node
    return this->levelGraph[index];
}

/*
 * @brief Get the level graph at a specific index.
 * @param index The index of the level graph to retrieve.
 * @return A vector representing the level graph at the specified index.
 * @pre The Graph object must exist.
 * @post A vector representing the level graph at the specified index is returned.
 */
const vector<vector<int>> &Graph::getLevelGraph() const { return this->levelGraph; }
// --------------------------------------------------------------------------------------------------------

// ---------------------------------------- Flow-related functions ----------------------------------------
/*
 * @brief Augment the flow in the graph based on a given augmenting path.
 * @param augmentingPath A vector representing the augmenting path.
 * @pre The Graph object must exist.
 * @post The flow in the graph is augmented using the given augmenting path.
 */
void Graph::augmentFlow(const vector<int> &augmentingPath)
{
    // Iterate through the nodes in the augmenting path
    for (int i = 0; i < augmentingPath.size() - 1; i++)
    {
        // Current node in the path
        int currentNode = augmentingPath[i];

        // Next node in the path
        int nextNodeIndex = i + 1;
        int nextNode = augmentingPath[nextNodeIndex];

        // Find the corresponding edge in the graph and augment its flow
        for (Edge &edge : this->edges)
        {
            // Check if the edge is in the direction of the augmenting path
            if (edge.getSourceIndex() == currentNode && edge.getDestinationIndex() == nextNode)
            {
                edge.setFlow(true); // Set the flow as true (augmenting the flow)
            }
            // Check if the edge is in the reverse direction of the augmenting path
            else if (edge.getSourceIndex() == nextNode && edge.getDestinationIndex() == currentNode)
            {
                edge.setFlow(false); // Set the flow as false (decreasing the flow)
            }
        }
    }
}

/*
 * @brief Remove a node and its incoming edges from the graph.
 * @param nodeIndex The index of the node to be removed.
 * @pre The Graph object must exist.
 * @post The specified node and its incoming edges are removed from the graph.
 */
void Graph::removeNodeAndIncomingEdges(int nodeIndex)
{
    // Delete the current node from the level graph
    this->levelGraph[nodeIndex].clear();

    // Delete all incoming edges to the current node
    for (int i = 0; i < this->levelGraph.size(); i++)
    {
        // Find the incoming edge in the adjacency list of each node
        vector<int>::iterator it = find(this->levelGraph[i].begin(), this->levelGraph[i].end(), nodeIndex);

        // If the incoming edge is found, remove it from the adjacency list
        if (it != this->levelGraph[i].end())
        {
            this->levelGraph[i].erase(it);
        }
    }
}
// --------------------------------------------------------------------------------------------------------
