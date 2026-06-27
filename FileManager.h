#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Graph.h"
#include <string>

class FileManager {
public:
    // Saves the graph's cities and roads to a specified text file
    static bool saveGraph(const Graph& graph, const std::string& filename);
    
    // Loads cities and roads from a specified text file into the graph
    static bool loadGraph(Graph& graph, const std::string& filename);
};

#endif // FILEMANAGER_H
