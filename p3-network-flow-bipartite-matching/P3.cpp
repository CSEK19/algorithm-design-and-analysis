/*
 * @file main.cpp
 * @brief Implementation of the Ford-Fulkerson algorithm for bipartite matching using the shortest augmenting paths method.
 *
 * This file reads data from an input file ("program3data.txt"), constructs a bipartite graph, and executes the Ford-Fulkerson
 * algorithm using the shortest augmenting paths method to find matches in the bipartite graph. It then prints the matches and
 * the total number of matches.
 *
 * @author Phat Tran
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Node.h"
#include "Graph.h"

using namespace std;

/*
 * @brief Main function for the Ford-Fulkerson algorithm with shortest augmenting paths for bipartite matching.
 *
 * @pre The input file "program3data.txt" exists and contains valid data for constructing a bipartite graph.
 *      The file format adheres to the specified structure, providing the number of nodes, node names, number
 *       of edges, and edge connections between nodes.
 *
 * @post The matches in the bipartite graph and the total number of matches are printed to the console.
 *       The graph object is properly constructed, and the necessary network flow operations are performed.
 *
 * @usage This function is called to execute the Ford-Fulkerson algorithm with the shortest augmenting paths
 *        method for bipartite matching.
 *
 * @return 0 on successful execution.
 */
int main()
{
    // Read data from the file
    const string inputFileName = "program3data.txt";
    ifstream inputFile(inputFileName);

    // Check if the file was opened successfully
    if (!inputFile.is_open())
    {
        cerr << "Error: Cannot open program3data.txt file." << endl;
        return 1;
    }

    Graph graph; // Instance of the Graph class

    // Load the nodes from the input file
    int nodeCount;
    inputFile >> nodeCount;

    for (int i = 0; i < nodeCount; i++)
    {
        // Read the name of the node from the input file
        string nodeName;
        inputFile >> nodeName;

        // Create a new node with the read information and add it to the graph
        Node newNode(nodeName, i + 1, 0);
        graph.addNode(newNode);
    }

    // Load the edges from the input file
    int edgeCount;
    inputFile >> edgeCount;

    for (int i = 0; i < edgeCount; i++)
    {
        // Read the source and destination indices (1-based indexing)
        int sourceIndex, destinationIndex;
        inputFile >> sourceIndex >> destinationIndex;

        // Convert to 0-based indexing
        sourceIndex--;
        destinationIndex--;

        // Add an edge to the graph with no flow initially (false)
        graph.addEdge(graph.getNode(sourceIndex).getIndex(), graph.getNode(destinationIndex).getIndex(), false);
    }

    inputFile.close();

    // Construct the residual graph
    graph.createResidualGraph();

    while (true)
    {
        // Build the level graph and check if there is a path from source to sink
        bool pathExists = graph.createLevelGraph();

        // If there is no path from source to sink, the algorithm has finished executing
        if (!pathExists)
        {
            break;
        }

        // Start at the source node
        int currentNode = graph.getNode(0).getIndex();
        vector<int> currentPath;

        // Continue the loop while there are still reachable nodes in the level graph from the source
        while (!graph.getLevelGraphAt(0).empty())
        {
            // If the current node is the sink
            if (currentNode == nodeCount + 1)
            {
                currentPath.push_back(currentNode);     // Add the current node to the path
                graph.augmentFlow(currentPath);         // Increase the flow along the path
                graph.updateResidualGraph(currentPath); // Update the residual graph
                graph.updateLevelGraph(currentPath);    // Remove the used edges from the level graph
                currentNode = 0;                        // Return to the source
                currentPath.clear();                    // Clear the path
            }
            else
            {
                // If the current node has no outgoing edges in the level graph, retreat (go back)
                if (graph.getLevelGraphAt(currentNode).empty())
                {
                    graph.removeNodeAndIncomingEdges(currentNode); // Remove the current node and its incoming edges
                    currentNode = currentPath.back();              // Update the current node to the previous node in the current path
                    currentPath.pop_back();                        // Remove the last node from the current path
                }
                else
                {
                    // Otherwise, move to the next node in the level graph
                    vector<int>::const_iterator it = graph.getLevelGraphAt(currentNode).begin();
                    currentPath.push_back(currentNode); // Add the current node to the path
                    currentNode = *it;                  // Move to the next node
                }
            }
        }
    }

    // Print the matches
    int matchCount = 0;
    for (const Edge &edge : graph.getEdges())
    {
        // Check if the edge has flow, indicating a matched pair
        if (edge.hasFlow())
        {
            const Node &sourceNode = graph.getNode(edge.getSourceIndex());
            const Node &destinationNode = graph.getNode(edge.getDestinationIndex());

            // Output the matched pair of nodes
            cout << sourceNode.getName() << " / " << destinationNode.getName() << endl;
            matchCount++;
        }
    }

    // Output the total number of matches
    cout << matchCount << " total matches" << endl;

    return 0;
}
