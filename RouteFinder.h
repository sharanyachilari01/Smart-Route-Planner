#ifndef ROUTEFINDER_H
#define ROUTEFINDER_H

#include "Graph.h"
#include <vector>
#include <string>

class RouteFinder {
public:
    // Finds and prints the shortest path between two cities using Dijkstra's algorithm
    static void findShortestPath(const Graph& graph, const std::string& start, const std::string& end);
    
    // Performs and prints Breadth-First Search traversal starting from a city
    static void bfsTraversal(const Graph& graph, const std::string& start);
    
    // Performs and prints Depth-First Search traversal starting from a city
    static void dfsTraversal(const Graph& graph, const std::string& start);
};

#endif // ROUTEFINDER_H
